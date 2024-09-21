#include <stdio.h>
#include <string.h>

#define MAX_RULES 1024
#define MAX_PACKETS 1024
#define ADDRESS_LEN 8
#define MAX_MESSAGE_LEN 50

// Structure to represent a filtering rule
typedef struct {
    char source_pattern[ADDRESS_LEN + 1];
    char destination_pattern[ADDRESS_LEN + 1];
    int permit; // 1 for permit, 0 for deny
} Rule;

// Structure to represent a network packet
typedef struct {
    char source_address[ADDRESS_LEN + 1];
    char destination_address[ADDRESS_LEN + 1];
    char message_body[MAX_MESSAGE_LEN + 1];
} Packet;

// Function to check if a string matches a pattern
int match(char *string, char *pattern) {
    int i;
    for (i = 0; i < ADDRESS_LEN; i++) {
        if (pattern[i] == '?' || string[i] == pattern[i]) {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}

// Function to check if a packet is permitted by the firewall
int is_permitted(Packet packet, Rule *rules, int num_rules) {
    int i;
    for (i = num_rules - 1; i >= 0; i--) {
        if (match(packet.source_address, rules[i].source_pattern) &&
            match(packet.destination_address, rules[i].destination_pattern)) {
            return rules[i].permit;
        }
    }
    return 0; // Default rule: deny
}

int main() {
    int n, m;
    Rule rules[MAX_RULES];
    Packet packets[MAX_PACKETS];
    int num_rules = 0;
    int num_packets = 0;

    // Read input data sets
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }

        // Read filtering rules
        for (int i = 0; i < n; i++) {
            char keyword[10];
            scanf("%s %s %s", keyword, rules[i].source_pattern, rules[i].destination_pattern);
            rules[i].permit = (strcmp(keyword, "permit") == 0) ? 1 : 0;
            num_rules++;
        }

        // Read packets
        for (int i = 0; i < m; i++) {
            scanf("%s %s %s", packets[i].source_address, packets[i].destination_address, packets[i].message_body);
            num_packets++;
        }

        // Check legality of each packet and print legal packets
        int legal_packet_count = 0;
        for (int i = 0; i < num_packets; i++) {
            if (is_permitted(packets[i], rules, num_rules)) {
                legal_packet_count++;
                printf("%s %s %s\n", packets[i].source_address, packets[i].destination_address, packets[i].message_body);
            }
        }

        printf("%d\n", legal_packet_count);
        num_rules = 0;
        num_packets = 0;
    }

    return 0;
}