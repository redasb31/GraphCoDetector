#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50

int H, W, C, M, NW, NC, NM;
int hero_with_warrior[MAX_N][MAX_N];
int warrior_with_cleric[MAX_N][MAX_N];
int cleric_with_mage[MAX_N][MAX_N];
int used_hero[MAX_N];
int used_warrior[MAX_N];
int used_cleric[MAX_N];
int used_mage[MAX_N];

int max_parties(int current_hero, int current_warrior, int current_cleric, int current_mage, int num_parties) {
    // Base case: All adventurers are used or the maximum number of parties without a specific adventurer is reached.
    if (current_hero == H || current_warrior == W || current_cleric == C || current_mage == M ||
        (current_warrior == W && NW > 0) || (current_cleric == C && NC > 0) || (current_mage == M && NM > 0)) {
        return num_parties;
    }

    int max_parties_so_far = num_parties;
    // Try forming a party with a hero.
    for (int i = current_hero; i < H; i++) {
        if (!used_hero[i]) {
            used_hero[i] = 1;
            // Try forming a party with a warrior.
            for (int j = current_warrior; j < W; j++) {
                if (!used_warrior[j] && hero_with_warrior[i][j]) {
                    used_warrior[j] = 1;
                    // Try forming a party with a cleric.
                    for (int k = current_cleric; k < C; k++) {
                        if (!used_cleric[k] && warrior_with_cleric[j][k]) {
                            used_cleric[k] = 1;
                            // Try forming a party with a mage.
                            for (int l = current_mage; l < M; l++) {
                                if (!used_mage[l] && cleric_with_mage[k][l]) {
                                    used_mage[l] = 1;
                                    max_parties_so_far = max(max_parties_so_far,
                                                            max_parties(i + 1, j + 1, k + 1, l + 1, num_parties + 1));
                                    used_mage[l] = 0;
                                }
                            }
                            used_cleric[k] = 0;
                        }
                    }
                    used_warrior[j] = 0;
                }
            }
            used_hero[i] = 0;
        }
    }

    // Try forming a party without a cleric.
    if (NC > 0 && current_warrior < W && current_mage < M) {
        for (int j = current_warrior; j < W; j++) {
            if (!used_warrior[j]) {
                used_warrior[j] = 1;
                for (int l = current_mage; l < M; l++) {
                    if (!used_mage[l]) {
                        used_mage[l] = 1;
                        max_parties_so_far = max(max_parties_so_far,
                                                max_parties(current_hero, j + 1, current_cleric, l + 1, num_parties + 1));
                        used_mage[l] = 0;
                    }
                }
                used_warrior[j] = 0;
            }
        }
        NC--;
    }

    // Try forming a party without a warrior.
    if (NW > 0 && current_cleric < C && current_mage < M) {
        for (int k = current_cleric; k < C; k++) {
            if (!used_cleric[k]) {
                used_cleric[k] = 1;
                for (int l = current_mage; l < M; l++) {
                    if (!used_mage[l]) {
                        used_mage[l] = 1;
                        max_parties_so_far = max(max_parties_so_far,
                                                max_parties(current_hero, current_warrior, k + 1, l + 1, num_parties + 1));
                        used_mage[l] = 0;
                    }
                }
                used_cleric[k] = 0;
            }
        }
        NW--;
    }

    // Try forming a party without a mage.
    if (NM > 0 && current_warrior < W && current_cleric < C) {
        for (int j = current_warrior; j < W; j++) {
            if (!used_warrior[j]) {
                used_warrior[j] = 1;
                for (int k = current_cleric; k < C; k++) {
                    if (!used_cleric[k]) {
                        used_cleric[k] = 1;
                        max_parties_so_far = max(max_parties_so_far,
                                                max_parties(current_hero, j + 1, k + 1, current_mage, num_parties + 1));
                        used_cleric[k] = 0;
                    }
                }
                used_warrior[j] = 0;
            }
        }
        NM--;
    }

    return max_parties_so_far;
}

int main() {
    while (1) {
        scanf("%d %d %d %d %d %d %d", &H, &W, &C, &M, &NW, &NC, &NM);
        if (H < 0) {
            break;
        }

        // Initialize compatibility arrays.
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                hero_with_warrior[j][i] = 0;
            }
        }
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < W; j++) {
                warrior_with_cleric[j][i] = 0;
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < C; j++) {
                cleric_with_mage[j][i] = 0;
            }
        }

        // Read compatibility data.
        for (int i = 0; i < W; i++) {
            int num_heroes;
            scanf("%d", &num_heroes);
            for (int j = 0; j < num_heroes; j++) {
                int hero_id;
                scanf("%d", &hero_id);
                hero_with_warrior[hero_id - 1][i] = 1;
            }
        }
        for (int i = 0; i < C; i++) {
            int num_warriors;
            scanf("%d", &num_warriors);
            for (int j = 0; j < num_warriors; j++) {
                int warrior_id;
                scanf("%d", &warrior_id);
                warrior_with_cleric[warrior_id - 1][i] = 1;
            }
        }
        for (int i = 0; i < M; i++) {
            int num_clerics;
            scanf("%d", &num_clerics);
            for (int j = 0; j < num_clerics; j++) {
                int cleric_id;
                scanf("%d", &cleric_id);
                cleric_with_mage[cleric_id - 1][i] = 1;
            }
        }

        // Find the maximum number of parties.
        printf("%d\n", max_parties(0, 0, 0, 0, 0));
    }
    return 0;
}