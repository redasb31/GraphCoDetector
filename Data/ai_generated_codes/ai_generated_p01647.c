#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a card
typedef struct {
    char suit;
    char rank;
} Card;

// Function to compare two cards based on their rank
int compare_cards(const void *a, const void *b) {
    Card *card1 = (Card *)a;
    Card *card2 = (Card *)b;

    // Special case for Ace (A)
    if (card1->rank == 'A') {
        if (card2->rank == 'A') {
            return 0; // Both are Ace, no difference
        } else if (card2->rank == '2') {
            return 1; // Ace is higher than 2
        } else {
            return -1; // Ace is higher than other ranks
        }
    } else if (card2->rank == 'A') {
        if (card1->rank == '2') {
            return -1; // 2 is lower than Ace
        } else {
            return 1; // Other ranks are lower than Ace
        }
    }

    // Compare ranks directly for other cards
    return card2->rank - card1->rank; // Descending order (highest first)
}

// Function to calculate the strength of a hand
int hand_strength(Card *hand, int hand_size) {
    // Sort the cards in descending order of rank
    qsort(hand, hand_size, sizeof(Card), compare_cards);

    // Check for the strongest hands first
    if (hand_size == 5 && 
        hand[0].rank == 'A' && hand[1].rank == 'K' && hand[2].rank == 'Q' && 
        hand[3].rank == 'J' && hand[4].rank == 'T' &&
        hand[0].suit == hand[1].suit && hand[0].suit == hand[2].suit &&
        hand[0].suit == hand[3].suit && hand[0].suit == hand[4].suit) {
        return 10; // Royal Flush
    } else if (hand_size == 5 && 
               hand[0].rank - hand[4].rank == 4 &&
               hand[0].suit == hand[1].suit && hand[0].suit == hand[2].suit &&
               hand[0].suit == hand[3].suit && hand[0].suit == hand[4].suit) {
        return 9; // Straight Flush
    } else if (hand_size == 5 && 
               hand[0].rank == hand[1].rank && hand[0].rank == hand[2].rank && 
               hand[0].rank == hand[3].rank) {
        return 8; // Four of a Kind
    } else if (hand_size == 5 && 
               hand[0].rank == hand[1].rank && hand[0].rank == hand[2].rank && 
               hand[3].rank == hand[4].rank) {
        return 7; // Full House
    } else if (hand_size == 5 && 
               hand[0].suit == hand[1].suit && hand[0].suit == hand[2].suit &&
               hand[0].suit == hand[3].suit && hand[0].suit == hand[4].suit) {
        return 6; // Flush
    } else if (hand_size == 5 && 
               hand[0].rank - hand[4].rank == 4) {
        return 5; // Straight
    } else if (hand_size == 5 && 
               hand[0].rank == hand[1].rank && hand[0].rank == hand[2].rank) {
        return 4; // Three of a Kind
    } else if (hand_size == 5 && 
               hand[0].rank == hand[1].rank && hand[2].rank == hand[3].rank) {
        return 3; // Two Pairs
    } else if (hand_size == 5 && 
               hand[0].rank == hand[1].rank) {
        return 2; // One Pair
    } else {
        return 1; // High Card
    }
}

// Function to compare two hands based on their strength and card ranks
int compare_hands(Card *hand1, int hand1_size, Card *hand2, int hand2_size) {
    // Calculate hand strengths
    int strength1 = hand_strength(hand1, hand1_size);
    int strength2 = hand_strength(hand2, hand2_size);

    // Compare strengths
    if (strength1 > strength2) {
        return 1; // Hand1 is stronger
    } else if (strength1 < strength2) {
        return -1; // Hand2 is stronger
    } else {
        // Same strength, compare card ranks
        int i = 0;
        while (i < hand1_size && i < hand2_size) {
            int cmp = compare_cards(&hand1[i], &hand2[i]);
            if (cmp != 0) {
                return cmp;
            }
            i++;
        }
        // If all compared cards are equal, the hand with more cards wins
        if (hand1_size > hand2_size) {
            return 1;
        } else if (hand1_size < hand2_size) {
            return -1;
        } else {
            return 0; // Both hands are equal
        }
    }
}

// Function to create a card from a string representation
Card create_card(const char *card_str) {
    Card card;
    card.suit = card_str[0];
    card.rank = card_str[1];
    return card;
}

// Function to calculate the probability of winning
double calculate_probability(Card *your_cards, Card *opponent_cards, Card *community_cards) {
    // Initialize variables
    int total_wins = 0;
    int total_games = 0;
    int deck_size = 52;
    Card deck[52];
    int i, j;

    // Create a deck of cards
    for (i = 0; i < 52; i++) {
        deck[i].suit = "SHDC"[i / 13];
        deck[i].rank = "AKQJT98765432"[i % 13];
    }

    // Remove cards already in play from the deck
    for (i = 0; i < 2; i++) {
        for (j = 0; j < deck_size; j++) {
            if (deck[j].suit == your_cards[i].suit && deck[j].rank == your_cards[i].rank) {
                deck[j] = deck[deck_size - 1]; // Swap with the last card
                deck_size--;
                break;
            }
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < deck_size; j++) {
            if (deck[j].suit == opponent_cards[i].suit && deck[j].rank == opponent_cards[i].rank) {
                deck[j] = deck[deck_size - 1]; // Swap with the last card
                deck_size--;
                break;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < deck_size; j++) {
            if (deck[j].suit == community_cards[i].suit && deck[j].rank == community_cards[i].rank) {
                deck[j] = deck[deck_size - 1]; // Swap with the last card
                deck_size--;
                break;
            }
        }
    }

    // Simulate all possible turn and river cards
    for (i = 0; i < deck_size; i++) {
        for (j = i + 1; j < deck_size; j++) {
            // Create hands for both players
            Card your_hand[7] = {your_cards[0], your_cards[1], community_cards[0], community_cards[1], community_cards[2], deck[i], deck[j]};
            Card opponent_hand[7] = {opponent_cards[0], opponent_cards[1], community_cards[0], community_cards[1], community_cards[2], deck[i], deck[j]};

            // Compare the hands
            int result = compare_hands(your_hand, 7, opponent_hand, 7);

            // Update wins and total games
            total_games++;
            if (result >= 1) { // You win
                total_wins++;
            }
        }
    }

    // Calculate and return the probability of winning
    return (double)total_wins / total_games;
}

int main() {
    Card your_cards[2];
    Card opponent_cards[2];
    Card community_cards[3];
    char card_str[3];

    // Read input data
    while (scanf("%s %s", card_str, card_str + 2) == 2) {
        your_cards[0] = create_card(card_str);
        your_cards[1] = create_card(card_str + 2);
        scanf("%s %s", card_str, card_str + 2);
        opponent_cards[0] = create_card(card_str);
        opponent_cards[1] = create_card(card_str + 2);
        scanf("%s %s %s", card_str, card_str + 2, card_str + 4);
        community_cards[0] = create_card(card_str);
        community_cards[1] = create_card(card_str + 2);
        community_cards[2] = create_card(card_str + 4);

        // Calculate and print the probability
        double probability = calculate_probability(your_cards, opponent_cards, community_cards);
        printf("%.16lf\n", probability);
    }

    return 0;
}