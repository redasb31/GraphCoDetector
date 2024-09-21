#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 50000
#define MAX_NAME_LEN 20

// Structure to represent a member
typedef struct {
    char name[MAX_NAME_LEN + 1];
    int motivation;
    int rank;
    int is_workhorse; // 1 if workhorse, 0 if idle
} Member;

// Structure to represent a change event
typedef struct {
    char type; // '+' for incoming, '-' for outgoing
    char name[MAX_NAME_LEN + 1];
    int motivation; // Only for incoming members
} Event;

// Function to compare members by motivation and rank
int compare_members(const void *a, const void *b) {
    Member *member_a = (Member *)a;
    Member *member_b = (Member *)b;

    if (member_a->motivation != member_b->motivation) {
        return member_b->motivation - member_a->motivation; // Descending order by motivation
    } else {
        return member_a->rank - member_b->rank; // Ascending order by rank
    }
}

// Function to find a member by name
Member *find_member(Member *members, int num_members, char *name) {
    for (int i = 0; i < num_members; i++) {
        if (strcmp(members[i].name, name) == 0) {
            return &members[i];
        }
    }
    return NULL;
}

int main() {
    int N, M;
    Member members[MAX_MEMBERS];
    Event events[MAX_MEMBERS];
    int num_members = 0;
    int num_events = 0;

    // Read initial members
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s %d", members[i].name, &members[i].motivation);
        members[i].rank = i; // Assign rank based on order of input
        num_members++;
    }

    // Read incoming/outgoing events
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        char buffer[50];
        scanf("%s", buffer);
        if (buffer[0] == '+') {
            events[i].type = '+';
            sscanf(buffer + 1, "%s %d", events[i].name, &events[i].motivation);
        } else {
            events[i].type = '-';
            sscanf(buffer + 1, "%s", events[i].name);
        }
        num_events++;
    }

    // Sort members by motivation and rank
    qsort(members, num_members, sizeof(Member), compare_members);

    // Process events
    for (int i = 0; i < num_events; i++) {
        Event *event = &events[i];

        // Handle incoming event
        if (event->type == '+') {
            // Add new member
            strcpy(members[num_members].name, event->name);
            members[num_members].motivation = event->motivation;
            members[num_members].rank = num_members;
            num_members++;

            // Sort members again
            qsort(members, num_members, sizeof(Member), compare_members);

            // Check if new member should be a workhorse
            if (num_members > 20) {
                printf("%s is not working now.\n", event->name);
            } else {
                printf("%s is working hard now.\n", event->name);
            }
        } else { // Handle outgoing event
            Member *member = find_member(members, num_members, event->name);

            // If the member exists
            if (member != NULL) {
                // Remove the member
                int index = member - members;
                for (int j = index; j < num_members - 1; j++) {
                    members[j] = members[j + 1];
                }
                num_members--;

                // Check if someone should start working
                if (num_members < 20) {
                    // Find the highest-ranked idle member
                    int highest_rank = -1;
                    for (int j = 0; j < num_members; j++) {
                        if (!members[j].is_workhorse && (highest_rank == -1 || members[j].rank < highest_rank)) {
                            highest_rank = members[j].rank;
                            member = &members[j];
                        }
                    }

                    // If an idle member is found, mark them as a workhorse
                    if (highest_rank != -1) {
                        member->is_workhorse = 1;
                        printf("%s is working hard now.\n", member->name);
                    }
                }
            }
        }
    }

    return 0;
}