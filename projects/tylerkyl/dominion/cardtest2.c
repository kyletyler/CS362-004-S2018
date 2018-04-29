/* Unit tests for great hall card
 * 
 * Description:
 *  Draws 1 card and adds 1 action
 * 
 * Operations:
 *  drawCard()
 *  discardCard()
 *
 * Tests:
 *  Current player should receive 1 and only 1 cards
 *  1 cards should come from current players pile
 *  Actions in current state are incremented by 1
 *  No state change should occur for other players
 *  No state change should occur to the victory card piles and kingdom card piles
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TESTCARD "great_hall"

int main() {
    int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;
    int i;
    int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
    struct gameState G, test_G;
    int test_k[10];
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, great_hall, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    ////////////////////////////////////////////////////////
    // TEST 1: Current player recieves 1 and only 1 cards //
    ////////////////////////////////////////////////////////
    
    // Copy the game state to the test game state
    memcpy(&test_G, &G, sizeof(struct gameState));
    cardEffect(great_hall, choice1, choice2, choice3, &test_G, handPos, &bonus);

    newCards = 1;
    printf("hand count = %d, expected = %d\t", test_G.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    if(test_G.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) 
        printf("great_hall test: PASS\n");
    else
        printf("great_hall test: FAIL\n");

    ///////////////////////////////////////////////////////////
    // TEST 2: Cards recieved are from current player's pile //
    ///////////////////////////////////////////////////////////
    
    // Copy the game state to the test game state
    memcpy(&test_G, &G, sizeof(struct gameState));
    cardEffect(great_hall, choice1, choice2, choice3, &test_G, handPos, &bonus);
    
    printf("deck count = %d, expected = %d\t", test_G.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    if(test_G.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards) 
        printf("great_hall test: PASS\n");
    else
        printf("great_hall test: FAIL\n");

    //////////////////////////////////////////
    // TEST 3: Actions are incremented by 1 //
    //////////////////////////////////////////

    // Copy the game state to the test game state
    memcpy(&test_G, &G, sizeof(struct gameState));
    cardEffect(great_hall, choice1, choice2, choice3, &test_G, handPos, &bonus);
    
    printf("actions count = %d, expected = %d\t", test_G.numActions, G.numActions + 1);
    if(test_G.numActions == G.numActions + 1) 
        printf("great_hall test: PASS\n");
    else
        printf("great_hall test: FAIL\n");

    ///////////////////////////////////////////////
    // TEST 4: No state change for other players //
    ///////////////////////////////////////////////
    
    // Copy the game state to the test game state
    memcpy(&test_G, &G, sizeof(struct gameState));

    cardEffect(great_hall, choice1, choice2, choice3, &test_G, handPos, &bonus);

    printf("otherPlayer handCount = %d, expected = %d\n", test_G.handCount[otherPlayer], G.handCount[otherPlayer]);
    printf("otherPlayer deckCount = %d, expected = %d\n", test_G.deckCount[otherPlayer], G.deckCount[otherPlayer]);
    printf("otherPlayer discardCount = %d, expected = %d\t", test_G.discardCount[otherPlayer], G.discardCount[otherPlayer]);
    
    if(test_G.handCount[otherPlayer] == G.handCount[otherPlayer] &&
       test_G.deckCount[otherPlayer] == G.deckCount[otherPlayer] &&
       test_G.discardCount[otherPlayer] == G.discardCount[otherPlayer])
        printf("great_hall test: PASS\n");
    else
        printf("great_hall test: FAIL\n");

    //////////////////////////////////////////////////////////////
    // TEST 5: No state change to victory or kingdom card piles //
    //////////////////////////////////////////////////////////////
    
    // Copy the game state to the test game state
    memcpy(&test_G, &G, sizeof(struct gameState));
    memcpy(&test_k, &k, sizeof(k));

    cardEffect(great_hall, choice1, choice2, choice3, &test_G, handPos, &bonus);

    // Checking changes to victory card piles
    printf("estate count = %d, expected = %d\n", test_G.supplyCount[estate], G.supplyCount[estate]);
    printf("duchy count = %d, expected = %d\n", test_G.supplyCount[duchy], G.supplyCount[duchy]);
    printf("province count = %d, expected = %d\t", test_G.supplyCount[province], G.supplyCount[province]);
    
    if(test_G.supplyCount[estate] == G.supplyCount[estate] &&
       test_G.supplyCount[duchy] == G.supplyCount[duchy] &&
       test_G.supplyCount[province] ==  G.supplyCount[province])
        printf("great_hall test: PASS\n");
    else
        printf("great_hall test: FAIL\n");

    // Checking changes to kingdom card piles
    for(i = 0; i < 10; i++)  {
        printf("kingdom card %d count = %d, expected = %d\t", i, k[i], test_k[i]);
        if(k[i] == test_k[i])
            printf("great_hall test: PASS\n");
        else
            printf("great_hall test: FAIL\n");
    }

    return 0;
}
