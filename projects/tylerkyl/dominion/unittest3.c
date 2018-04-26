// Unit test for dominion.c function supplyCount()

// supplyCount() description: returns the supply count of a specific card

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main() {
    int cardsReturned, i;
    struct gameState G;
    int startingCurse = 10;
    int startingDuchy = 0;
    int startingGold = 9;

    // Set starting supply values
    G.supplyCount[curse] = startingCurse;
    G.supplyCount[duchy] = startingDuchy;
    G.supplyCount[gold] = startingGold;

    printf("TESTING supplyCount():\n");
    
    // Testing function for different values
    for(i = 0; i <= startingCurse; i++) {
        
        // Curse test
        cardsReturned = supplyCount(curse, &G);
        printf("CURSE: cardsReturned = %d, expected = %d\n", cardsReturned, startingCurse - i );
        assert(cardsReturned == startingCurse - i); // check if the number of cards returned is correct
        G.supplyCount[curse]--;

        // Duchy test
        cardsReturned = supplyCount(duchy, &G);
        printf("DUCHY: cardsReturned = %d, expected = %d\n", cardsReturned, startingDuchy + i );
        assert(cardsReturned == startingDuchy + i); // check if the number of cards returned is correct
        G.supplyCount[duchy]++;

        // Gold test
        cardsReturned = supplyCount(gold, &G);
        printf("GOLD: cardsReturned = %d, expected = %d\n", cardsReturned, startingGold - i );
        assert(cardsReturned == startingGold - i); // check if the number of cards returned is correct
        G.supplyCount[gold]--;

        printf("\n");
    }

    printf("All tests passed!\n");

    return 0;
}
