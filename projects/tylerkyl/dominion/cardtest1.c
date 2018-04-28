/* Unit tests for smithy card
 * 
 * Description:
 *  Draws 3 cards
 * 
 * Operations:
 *  drawCard()
 *  discardCard()
 *
 * Tests:
 *  Current player should receive 3 and only three cards
 *  3 cards should come from current players pile
 *  No state change should occur for other players
 *  No state change should occur to the victory card piles and kingdom card piles
 */

// Remember: There are bugs in the smithy card!
// It draws the wrong number of cards and doesn't discard
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
    int newCards = 0;
    int discarded = 1;
    int extraCoins = 0;
    int shuffledCards = 0;
    int i, j, m;
    int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
    struct gameState G, test_G;
    int test_k[10];
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    ////////////////////////////////////////////////////////
    // TEST 1: Current player recieves 3 and only 3 cards //
    ////////////////////////////////////////////////////////
    
    // Copy the game state to the test game state
    memcpy(&test_G, &G, sizeof(struct gameState));
    cardEffect(smithy, choice1, choice2, choice3, &test_G, handPos, &bonus);

    newCards = 3;
    printf("hand count = %d, expected = %d\n", test_G.handCount[thisPlayer], G.handCount[thisPlayer]+ newCards - discarded);
    //assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded); 
    if(test_G.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) 
        printf("smithy test: PASS\n");
    else
        printf("smithy test: FAIL\n");


    ///////////////////////////////////////////////////////////
    // TEST 2: Cards recieved are from current player's pile //
    ///////////////////////////////////////////////////////////
    
    // Copy the game state to the test game state
    memcpy(&test_G, &G, sizeof(struct gameState));
    cardEffect(smithy, choice1, choice2, choice3, &test_G, handPos, &bonus);
    
    printf("deck count = %d, expected = %d\n", test_G.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
   // assert(test_G.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
    if(test_G.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards) 
        printf("smithy test: PASS\n");
    else
        printf("smithy test: FAIL\n");

    ///////////////////////////////////////////////
    // TEST 3: No state change for other players //
    ///////////////////////////////////////////////
    
    // Copy the game state to the test game state
    memcpy(&test_G, &G, sizeof(struct gameState));

    cardEffect(smithy, choice1, choice2, choice3, &test_G, handPos, &bonus);
   

    printf("otherPlayer handCount = %d, expected = %d\n", test_G.handCount[otherPlayer], G.handCount[otherPlayer]);
    printf("otherPlayer deckCount = %d, expected = %d\n", test_G.deckCount[otherPlayer], G.deckCount[otherPlayer]);
    printf("otherPlayer discardCount = %d, expected = %d\n", test_G.discardCount[otherPlayer], G.discardCount[otherPlayer]);
    
    if(test_G.handCount[otherPlayer] == G.handCount[otherPlayer] &&
       test_G.deckCount[otherPlayer] == G.deckCount[otherPlayer] &&
       test_G.discardCount[otherPlayer] == G.discardCount[otherPlayer])
        printf("smithy test: PASS\n");
    else
        printf("smithy test: FAIL\n");
/*
    if(test_G.handCount[otherPlayer] == G.handCount[otherPlayer] &&
       test_G.deckCount[otherPlayer] == G.deckCount[otherPlayer] &&
       test_G.discardCount[otherPlayer] == G.discardCount[otherPlayer]) {
        printf("\n");
    }
    else {
        printf("nah\n");
    }
*/

    //////////////////////////////////////////////////////////////
    // TEST 4: No state change to victory or kingdom card piles //
    //////////////////////////////////////////////////////////////
    
    // Copy the game state to the test game state
    memcpy(&test_G, &G, sizeof(struct gameState));
    memcpy(&test_k, &k, sizeof(k));

    cardEffect(smithy, choice1, choice2, choice3, &test_G, handPos, &bonus);

    // Checking changes to victory card piles
    printf("estate count = %d, expected = %d\n", test_G.supplyCount[estate], G.supplyCount[estate]);
    printf("duchy count = %d, expected = %d\n", test_G.supplyCount[duchy], G.supplyCount[duchy]);
    printf("province count = %d, expected = %d\n", test_G.supplyCount[province], G.supplyCount[province]);
    
    if(test_G.supplyCount[estate] == G.supplyCount[estate] &&
       test_G.supplyCount[duchy] == G.supplyCount[duchy] &&
       test_G.supplyCount[province] ==  G.supplyCount[province])
        printf("smithy test: PASS\n");
    else
        printf("smithy test: FAIL\n");

    // Checking changes to kingdom card piles
    for(i = 0; i < 10; i++)  {
        printf("kingdom card %d count = %d, expected = %d\n", i, k[i], test_k[i]);
        if(k[i] == test_k[i])
            printf("smithy test: PASS\n");
        else
            printf("smithy test: FAIL\n");
    }

    return 0;
}
