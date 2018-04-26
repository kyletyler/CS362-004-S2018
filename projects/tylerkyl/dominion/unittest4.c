// Unit test for dominion.c function isGameOver()

// isGameOver() description: Checks number of provinces or if three supply piles are empty to determine if the game is over
// returns 1 if game over, returns 0 if game not over

// There are 25 supply piles
// provinces are in position 3

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main() {
    int i;
    struct gameState G;

    // Put one card in each supply pile
    for(i = 0; i < 25; i++) {
        G.supplyCount[i]++;
    }

    printf("TESTING isGameOver():\n\n");
    
    // Testing game over by provinces
    printf("Testing provinces:\n");
    printf("Num Provinces = %d\n", G.supplyCount[province]);  
    printf("isGameOver = %d, expected = 0\n", isGameOver(&G));
    assert(isGameOver(&G) == 0); // Check if game is over
    
    G.supplyCount[province]--; // Remove the province card

    printf("Num Provinces = %d\n", G.supplyCount[province]);  
    printf("isGameOver = %d, expected = 1\n", isGameOver(&G));
    assert(isGameOver(&G) == 1); // Check if game is over

    G.supplyCount[province]++;

    // Testing game over by supply piles
    printf("\nTesting supply piles:\n");

    for(i = 0; i < 25; i++) {
        printf("G.supplyCount[%d] = %d\n", i, G.supplyCount[i]);
    }

    printf("isGameOver = %d, expected = 0\n", isGameOver(&G));
    assert(isGameOver(&G) == 0); // Check if game is over
   
    // Remove 2 cards
    printf("Removing 2 cards...\n");
    G.supplyCount[0]--;
    G.supplyCount[1]--;

    for(i = 0; i < 25; i++) {
        printf("G.supplyCount[%d] = %d\n", i, G.supplyCount[i]);
    }

    printf("isGameOver = %d, expected = 0\n", isGameOver(&G));
    assert(isGameOver(&G) == 0); // Check if game is over

    // Remove 1 card
    printf("Removing 1 card...\n");
    G.supplyCount[15]--;

    for(i = 0; i < 25; i++) {
        printf("G.supplyCount[%d] = %d\n", i, G.supplyCount[i]);
    }

    printf("isGameOver = %d, expected = 1\n", isGameOver(&G));
    assert(isGameOver(&G) == 1); // Check if game is over
   
    // Remove 1 card
    printf("Removing 1 card...\n");
    G.supplyCount[9]--;

    for(i = 0; i < 25; i++) {
        printf("G.supplyCount[%d] = %d\n", i, G.supplyCount[i]);
    }

    printf("isGameOver = %d, expected = 1\n", isGameOver(&G));
    assert(isGameOver(&G) == 1); // Check if game is over
    
    printf("All tests passed!\n");

    return 0;
}
