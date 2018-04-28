// Unit test for dominion.c function handCard()

/* handCard()
 * Description: returns the card in a specific position of the hand
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main() {
    int numPlayers = 2;
    int handCount, handPos, cardReturned;
    struct gameState G;
    int maxHandCount = 5;
    int i, p;
    
    int coppers[MAX_HAND];
    
    for(i = 0; i < MAX_HAND; i++) {
        coppers[i] = copper;
    }

    printf("----------TESTING handCard():----------\n");

    // Testing function for each player
    for(p = 0; p < numPlayers; p++) {
        // Testing function for each handCount
        for(handCount = 1; handCount <= maxHandCount; handCount++) {
            // Testing the function for each hand position
            // Filling the hand with copper for testing purposes (could use any combo of cards)
            for(handPos = 0; handPos < handCount; handPos++) {
                G.handCount[p] = handCount;
                memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
                cardReturned = handCard(handPos, &G);
            //    printf("p = %d, handCount = %d, handPos = %d\n", p, handCount, handPos);
                printf("cardReturned = %d, expected = %d\n", cardReturned, copper);
                //assert(cardReturned == copper);// Check that the card expected is returned
                if(cardReturned == copper)
                    printf("handCard() test: PASS\n");
                else
                    printf("handCard() test: FAIL\n");
            }
            printf("\n");
        }
    }


    return 0;
}
