// Unit test for dominion.c function supplyCount()

// supplyCount() description: returns the supply count of a specific card

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

    printf("----------TESTING supplyCount():----------\n");
    
    // Testing function for different values
    for(i = 0; i <= startingCurse; i++) {
        
        // Curse test
        cardsReturned = supplyCount(curse, &G);
        printf("CURSE: cardsReturned = %d, expected = %d\n", cardsReturned, startingCurse - i );
        if(cardsReturned == startingCurse - i)
            printf("supplyCount() test: PASS\n");
        else
            printf("supplyCount() test: FAIL\n");

        G.supplyCount[curse]--;

        // Duchy test
        cardsReturned = supplyCount(duchy, &G);
        printf("DUCHY: cardsReturned = %d, expected = %d\n", cardsReturned, startingDuchy + i );
        if(cardsReturned == startingDuchy + i)
            printf("supplyCount() test: PASS\n");
        else
            printf("supplyCount() test: FAIL\n");
        
        G.supplyCount[duchy]++;

        // Gold test
        cardsReturned = supplyCount(gold, &G);
        printf("GOLD: cardsReturned = %d, expected = %d\n", cardsReturned, startingGold - i );
        if(cardsReturned == startingGold - i)
            printf("supplyCount() test: PASS\n");
        else
            printf("supplyCount() test: FAIL\n");
        
        G.supplyCount[gold]--;

        printf("\n");
    }

    return 0;
}
