#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
  int left;
  int right;
  int row;
  char *text;
} Segment;

typedef struct {
  Segment segments[MAX_ROWS][MAX_COLS];
  int num_rows;
  int num_cols;
  int cursor_row;
  int cursor_col;
} Editor;

// Initializes an editor with a single segment containing the initial character
void init_editor(Editor *editor, char initial_char) {
  editor->num_rows = 1;
  editor->num_cols = 1;
  editor->cursor_row = 0;
  editor->cursor_col = 0;
  editor->segments[0][0].left = 0;
  editor->segments[0][0].right = 0;
  editor->segments[0][0].row = 0;
  editor->segments[0][0].text = malloc(2 * sizeof(char));
  editor->segments[0][0].text[0] = initial_char;
  editor->segments[0][0].text[1] = '\0';
}

// Frees memory allocated for segments
void free_editor(Editor *editor) {
  for (int i = 0; i < editor->num_rows; i++) {
    for (int j = 0; j < editor->num_cols; j++) {
      if (editor->segments[i][j].text != NULL) {
        free(editor->segments[i][j].text);
      }
    }
  }
}

// Finds the segment at the given row and column
Segment *find_segment(Editor *editor, int row, int col) {
  for (int i = 0; i < editor->num_rows; i++) {
    for (int j = 0; j < editor->num_cols; j++) {
      if (editor->segments[i][j].text != NULL &&
          row == editor->segments[i][j].row &&
          col >= editor->segments[i][j].left &&
          col <= editor->segments[i][j].right) {
        return &editor->segments[i][j];
      }
    }
  }
  return NULL;
}

// Moves the cursor to the specified position
void move_cursor(Editor *editor, int row, int col) {
  Segment *segment = find_segment(editor, row, col);
  if (segment == NULL) {
    printf("ERROR\n");
    exit(1);
  }
  editor->cursor_row = row;
  editor->cursor_col = col;
}

// Concatenates segments in the same row
void concatenate_segments(Editor *editor, int row) {
  for (int i = 0; i < editor->num_cols - 1; i++) {
    if (editor->segments[row][i].text != NULL &&
        editor->segments[row][i + 1].text != NULL &&
        editor->segments[row][i].right + 1 == editor->segments[row][i + 1].left) {
      int len1 = strlen(editor->segments[row][i].text);
      int len2 = strlen(editor->segments[row][i + 1].text);
      editor->segments[row][i].text = realloc(
          editor->segments[row][i].text,
          (len1 + len2 + 1) * sizeof(char));
      strcat(editor->segments[row][i].text, editor->segments[row][i + 1].text);
      editor->segments[row][i].right = editor->segments[row][i + 1].right;
      editor->segments[row][i + 1].text = NULL;
    }
  }
}

// Pulls down segments to fill empty space
void pull_down_segments(Editor *editor) {
  for (int i = editor->num_rows - 1; i > 0; i--) {
    for (int j = 0; j < editor->num_cols; j++) {
      if (editor->segments[i][j].text != NULL) {
        int empty = 1;
        for (int k = 0; k < editor->num_cols; k++) {
          if (editor->segments[i - 1][k].text != NULL) {
            empty = 0;
            break;
          }
        }
        if (empty) {
          editor->segments[i - 1][j] = editor->segments[i][j];
          editor->segments[i][j].text = NULL;
          editor->segments[i - 1][j].row--;
        }
      }
    }
  }
}

// Processes commands for the editor
void process_commands(Editor *editor, char *commands) {
  int i = 1; // Skip initial character
  while (commands[i] != '\0') {
    switch (commands[i]) {
      case 'F':
        if (editor->cursor_col == strlen(editor->segments[editor->cursor_row][editor->cursor_col].text) - 1) {
          printf("ERROR\n");
          free_editor(editor);
          exit(1);
        } else {
          editor->cursor_col++;
        }
        break;
      case 'B':
        if (editor->cursor_col == 0) {
          printf("ERROR\n");
          free_editor(editor);
          exit(1);
        } else {
          editor->cursor_col--;
        }
        break;
      case 'P':
        if (editor->cursor_row == 0 ||
            find_segment(editor, editor->cursor_row - 1, editor->cursor_col) == NULL) {
          printf("ERROR\n");
          free_editor(editor);
          exit(1);
        } else {
          editor->cursor_row--;
        }
        break;
      case 'N':
        if (editor->cursor_row == editor->num_rows - 1 ||
            find_segment(editor, editor->cursor_row + 1, editor->cursor_col) == NULL) {
          printf("ERROR\n");
          free_editor(editor);
          exit(1);
        } else {
          editor->cursor_row++;
        }
        break;
      case 'D':
        if (editor->cursor_col == strlen(editor->segments[editor->cursor_row][editor->cursor_col].text) - 1) {
          printf("ERROR\n");
          free_editor(editor);
          exit(1);
        } else {
          Segment *segment = &editor->segments[editor->cursor_row][editor->cursor_col];
          int len = strlen(segment->text);
          for (int j = editor->cursor_col; j < len - 1; j++) {
            segment->text[j] = segment->text[j + 1];
          }
          segment->text[len - 1] = '\0';
          if (strlen(segment->text) == 0) {
            segment->text = NULL;
            editor->cursor_row++;
            if (editor->cursor_row >= editor->num_rows) {
              editor->cursor_row = editor->num_rows - 1;
            }
          }
        }
        break;
      case 'C':
        if (editor->cursor_col == strlen(editor->segments[editor->cursor_row][editor->cursor_col].text) - 1 ||
            find_segment(editor, editor->cursor_row - 1, editor->cursor_col) != NULL) {
          printf("ERROR\n");
          free_editor(editor);
          exit(1);
        } else {
          Segment *segment = &editor->segments[editor->cursor_row][editor->cursor_col];
          editor->segments[editor->cursor_row - 1][editor->cursor_col].text = malloc(2 * sizeof(char));
          editor->segments[editor->cursor_row - 1][editor->cursor_col].text[0] = segment->text[editor->cursor_col];
          editor->segments[editor->cursor_row - 1][editor->cursor_col].text[1] = '\0';
          editor->segments[editor->cursor_row - 1][editor->cursor_col].left = editor->cursor_col;
          editor->segments[editor->cursor_row - 1][editor->cursor_col].right = editor->cursor_col;
          editor->segments[editor->cursor_row - 1][editor->cursor_col].row = editor->cursor_row - 1;
          editor->cursor_row--;
          editor->cursor_col++;
        }
        break;
      default:
        Segment *segment = &editor->segments[editor->cursor_row][editor->cursor_col];
        int len = strlen(segment->text);
        segment->text = realloc(segment->text, (len + 2) * sizeof(char));
        segment->text[len] = commands[i];
        segment->text[len + 1] = '\0';
        segment->right++;
        editor->cursor_col++;
        break;
    }
    // Apply gravity and concatenation after each command
    pull_down_segments(editor);
    concatenate_segments(editor, editor->cursor_row);
    i++;
  }
}

int main() {
  int num_sessions;
  scanf("%d", &num_sessions);
  getchar(); // Consume newline

  for (int i = 0; i < num_sessions; i++) {
    char commands[101];
    fgets(commands, 101, stdin);
    commands[strlen(commands) - 1] = '\0';

    Editor editor;
    init_editor(&editor, commands[0]);
    process_commands(&editor, commands);

    Segment *current_segment = &editor.segments[editor.cursor_row][editor.cursor_col];
    if (current_segment->text != NULL) {
      printf("%s\n", current_segment->text);
    } else {
      printf("ERROR\n");
    }
    free_editor(&editor);
  }

  return 0;
}