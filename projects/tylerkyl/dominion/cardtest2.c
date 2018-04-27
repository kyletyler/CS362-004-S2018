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
    struct gameStateG, test_G;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    ////////////////////////////////////////////////////////
    // TEST 1: Current player recieves 3 and only 3 cards //
    ////////////////////////////////////////////////////////
    
    // Copy the game state to the test game state
    memcpy(&test_G, &G, sizeof(struct gameState));


