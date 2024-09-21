#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 8
#define MAX_HEIGHT 8
#define MAX_HP 6

typedef struct {
  int x;
  int y;
  int hp;
} Ant;

typedef struct {
  int width;
  int height;
  int grid[MAX_HEIGHT][MAX_WIDTH];
  Ant ant;
} Map;

// Function to initialize a map from input
void init_map(Map *map) {
  int i, j;
  scanf("%d %d", &map->width, &map->height);
  for (i = 0; i < map->height; i++) {
    for (j = 0; j < map->width; j++) {
      scanf("%d", &map->grid[i][j]);
      if (map->grid[i][j] == 2) {
        map->ant.x = j;
        map->ant.y = i;
        map->ant.hp = MAX_HP;
      }
    }
  }
}

// Function to check if a move is valid
int is_valid_move(Map *map, int x, int y) {
  if (x < 0 || x >= map->width || y < 0 || y >= map->height ||
      map->grid[y][x] == 0) {
    return 0;
  }
  return 1;
}

// Function to perform a move and update the ant's state
void move_ant(Map *map, int x, int y) {
  map->ant.x = x;
  map->ant.y = y;
  map->ant.hp--;
  if (map->grid[y][x] == 4) {
    map->ant.hp = MAX_HP;
  }
}

// Function to find the minimum time to reach the hole using BFS
int find_min_time(Map *map) {
  int queue[MAX_WIDTH * MAX_HEIGHT][3]; // Queue to store ant states
  int front = 0, rear = 0;
  int visited[MAX_HEIGHT][MAX_WIDTH] = {0}; // Array to track visited cells
  
  // Add initial ant state to the queue
  queue[rear][0] = map->ant.x;
  queue[rear][1] = map->ant.y;
  queue[rear][2] = 0;
  rear++;
  visited[map->ant.y][map->ant.x] = 1;

  // Perform BFS
  while (front < rear) {
    int x = queue[front][0];
    int y = queue[front][1];
    int time = queue[front][2];
    front++;

    // Check if the hole is reached with positive HP
    if (map->grid[y][x] == 3 && map->ant.hp > 0) {
      return time;
    }

    // Explore possible moves
    if (is_valid_move(map, x + 1, y) && !visited[y][x + 1]) {
      move_ant(map, x + 1, y);
      queue[rear][0] = x + 1;
      queue[rear][1] = y;
      queue[rear][2] = time + 1;
      rear++;
      visited[y][x + 1] = 1;
      move_ant(map, x, y); // Reset ant state
    }
    if (is_valid_move(map, x - 1, y) && !visited[y][x - 1]) {
      move_ant(map, x - 1, y);
      queue[rear][0] = x - 1;
      queue[rear][1] = y;
      queue[rear][2] = time + 1;
      rear++;
      visited[y][x - 1] = 1;
      move_ant(map, x, y);
    }
    if (is_valid_move(map, x, y + 1) && !visited[y + 1][x]) {
      move_ant(map, x, y + 1);
      queue[rear][0] = x;
      queue[rear][1] = y + 1;
      queue[rear][2] = time + 1;
      rear++;
      visited[y + 1][x] = 1;
      move_ant(map, x, y);
    }
    if (is_valid_move(map, x, y - 1) && !visited[y - 1][x]) {
      move_ant(map, x, y - 1);
      queue[rear][0] = x;
      queue[rear][1] = y - 1;
      queue[rear][2] = time + 1;
      rear++;
      visited[y - 1][x] = 1;
      move_ant(map, x, y);
    }
  }

  return -1; // Ant cannot reach the hole
}

int main() {
  Map map;
  while (1) {
    init_map(&map);
    if (map.width == 0 && map.height == 0) {
      break;
    }
    printf("%d\n", find_min_time(&map));
  }
  return 0;
}