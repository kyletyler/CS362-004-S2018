// Unit test for dominion.c function updateCoins()

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main() {
    int seed = 1000;
    int numPlayers = 2;
    int maxBonus = 10;
    int r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    // Arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];

    int i;
    for(i = 0; i < MAX_HAND; i++) {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf("----------TESTING updateCoins():----------\n");
    
    int p;
    for(p = 0; p < numPlayers; p++) {
        
        for(handCount = 1; handCount <= maxHandCount; handCount++) {

            for (bonus = 0; bonus <= maxBonus; bonus++) {
                
                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
                memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
                updateCoins(p, &G, bonus);
                printf("G.coins = %d, expected = %d\t", G.coins, handCount * 1 + bonus);
                //assert(G.coins == handCount * 1 + bonus); // check if the number of coins is correct
                if(G.coins == handCount * 1 + bonus)
                    printf("updateCoins() test: PASS\n");
                else
                    printf("updateCoins() test: FAIL\n");

                memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silver
                updateCoins(p, &G, bonus);
                printf("G.coins = %d, expected = %d\t", G.coins, handCount * 2 + bonus);
                //assert(G.coins == handCount * 2 + bonus); // check if the number of coins is correct
                if(G.coins == handCount * 2 + bonus)
                    printf("updateCoins() test: PASS\n");
                else
                    printf("updateCoins() test: FAIL\n");

                memcpy(G.hand[p], golds, sizeof(int) * handCount); // set all the cards to gold
                updateCoins(p, &G, bonus);
                printf("G.coins = %d, expected = %d\t", G.coins, handCount * 3 + bonus);
                //assert(G.coins == handCount * 3 + bonus); // check if the number of coins is correct
                if(G.coins == handCount * 3 + bonus)
                    printf("updateCoins() test: PASS\n");
                else
                    printf("updateCoins() test: FAIL\n");
            }                                                      
        }
    }

    return 0;
}
