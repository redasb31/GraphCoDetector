#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEALERS 100
#define MAX_ORDERS 1000
#define MAX_COMMODITIES 26

typedef struct {
    char dealer[10];
    char type[4];
    char commodity;
    int price;
} Order;

typedef struct {
    int lowest;
    int average;
    int highest;
} CommodityStats;

typedef struct {
    int paid;
    int received;
} DealerStats;

int main() {
    Order orders[MAX_ORDERS];
    CommodityStats commodityStats[MAX_COMMODITIES];
    DealerStats dealerStats[MAX_DEALERS];
    int nOrders;
    int orderCount = 0;
    int commodityIndex;
    int dealerIndex;
    int dealCount = 0;
    int totalDeals = 0;
    int lowestPrice, highestPrice;
    char commodityName;

    // Initialize data structures
    for (int i = 0; i < MAX_COMMODITIES; i++) {
        commodityStats[i].lowest = 1000; // Initialize lowest price to a high value
        commodityStats[i].highest = 0;   // Initialize highest price to a low value
    }

    while (1) {
        scanf("%d", &nOrders);
        if (nOrders == 0) {
            break;
        }

        // Reset data structures for each day
        orderCount = 0;
        dealCount = 0;
        totalDeals = 0;
        memset(dealerStats, 0, sizeof(dealerStats));
        memset(commodityStats, 0, sizeof(commodityStats));

        // Read orders for the day
        for (int i = 0; i < nOrders; i++) {
            scanf("%s %s %c %d", orders[i].dealer, orders[i].type, &orders[i].commodity, &orders[i].price);
            orderCount++;
        }

        // Process orders
        for (int i = 0; i < orderCount; i++) {
            // Find matching order for buy/sell
            int matchIndex = -1;
            if (strcmp(orders[i].type, "BUY") == 0) {
                // Find the lowest sell order
                lowestPrice = 1000;
                for (int j = i + 1; j < orderCount; j++) {
                    if (strcmp(orders[j].type, "SELL") == 0 && orders[j].commodity == orders[i].commodity && orders[j].price <= lowestPrice && strcmp(orders[j].dealer, orders[i].dealer) != 0) {
                        matchIndex = j;
                        lowestPrice = orders[j].price;
                    }
                }
            } else {
                // Find the highest buy order
                highestPrice = 0;
                for (int j = i + 1; j < orderCount; j++) {
                    if (strcmp(orders[j].type, "BUY") == 0 && orders[j].commodity == orders[i].commodity && orders[j].price >= highestPrice && strcmp(orders[j].dealer, orders[i].dealer) != 0) {
                        matchIndex = j;
                        highestPrice = orders[j].price;
                    }
                }
            }

            // If a match is found, make a deal
            if (matchIndex != -1) {
                int dealPrice = (orders[i].price + orders[matchIndex].price) / 2;
                dealCount++;
                totalDeals++;

                // Update commodity stats
                commodityIndex = orders[i].commodity - 'A';
                commodityStats[commodityIndex].highest = (dealPrice > commodityStats[commodityIndex].highest) ? dealPrice : commodityStats[commodityIndex].highest;
                commodityStats[commodityIndex].lowest = (dealPrice < commodityStats[commodityIndex].lowest) ? dealPrice : commodityStats[commodityIndex].lowest;
                commodityStats[commodityIndex].average += dealPrice;

                // Update dealer stats
                dealerIndex = 0;
                while (strcmp(orders[i].dealer, dealerStats[dealerIndex].dealer) != 0 && dealerIndex < MAX_DEALERS) {
                    dealerIndex++;
                }
                if (dealerIndex == MAX_DEALERS) {
                    strcpy(dealerStats[dealerIndex].dealer, orders[i].dealer);
                }
                if (strcmp(orders[i].type, "BUY") == 0) {
                    dealerStats[dealerIndex].paid += dealPrice;
                } else {
                    dealerStats[dealerIndex].received += dealPrice;
                }

                // Update dealer stats for the matching order
                dealerIndex = 0;
                while (strcmp(orders[matchIndex].dealer, dealerStats[dealerIndex].dealer) != 0 && dealerIndex < MAX_DEALERS) {
                    dealerIndex++;
                }
                if (dealerIndex == MAX_DEALERS) {
                    strcpy(dealerStats[dealerIndex].dealer, orders[matchIndex].dealer);
                }
                if (strcmp(orders[matchIndex].type, "BUY") == 0) {
                    dealerStats[dealerIndex].paid += dealPrice;
                } else {
                    dealerStats[dealerIndex].received += dealPrice;
                }
            }
        }

        // Print commodity stats
        printf("A %d %d %d\n", commodityStats[0].lowest, commodityStats[0].average / totalDeals, commodityStats[0].highest);
        for (int i = 1; i < MAX_COMMODITIES; i++) {
            if (commodityStats[i].highest != 0) {
                commodityName = i + 'A';
                printf("%c %d %d %d\n", commodityName, commodityStats[i].lowest, commodityStats[i].average / totalDeals, commodityStats[i].highest);
            }
        }

        printf("–\n");

        // Print dealer stats
        for (int i = 0; i < MAX_DEALERS; i++) {
            if (strcmp(dealerStats[i].dealer, "") != 0) {
                printf("%s %d %d\n", dealerStats[i].dealer, dealerStats[i].paid, dealerStats[i].received);
            }
        }

        printf("———————\n");
    }

    return 0;
}