// Unittest5.c
// Tobias Hodges
// 10 November 2019
// CS 362 F19

#include "dominion.c"
#include <stdio.h>
#include <string.h>

int main() {

    int seed = 1;
    int card = 0;
    int handPos = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handCount = 3;
    int bonus = 0;
    int j = 0;
    int p = 0;
    int currentPlayer = 0;
    int nextPlayer = 1;
    int tributeRevealedCards[2] = {
        0, 1
    };

    // set your card array
    int k[5] = { tribute, ambassador, gold, great_hall };
    // declare the game state
    struct gameState G;

    printf("Begin test: minePlayed()\n");

    // set the state of your variables
    memset(&G, 23, sizeof(struct gameState));
    int r = initializeGame(2, k, seed, &G);
    G.handCount[p] = handCount;
    memcpy(G.hand[p], k, sizeof(int) * handCount);

    // call the refactored function
    tributePlayed(card, &G, 1, choice2, choice3, handPos, &bonus, currentPlayer, nextPlayer, tributeRevealedCards);
    
    // verify that your asserts pass, for the bugs your asserts may fail
    assert(G.numActions == 2); // check a assert(some condition);

    // adjust the state of your variables to
    // comment on what this is going to test //
    memset(&G, 0, sizeof(struct gameState));
    r = initializeGame(3, k, seed, &G); 
    G.handCount[p] = handCount;
    memcpy(G.hand[p], k, sizeof(int) * handCount);
    
    // call the refactored function again
    tributePlayed(card, &G, 2, choice2, choice3, handPos, &bonus, currentPlayer, nextPlayer, tributeRevealedCards);

    // continue testing the function
    assert(G.coins == 2);
        // adjust the state of your variables to
    // comment on what this is going to test //
    memset(&G, 0, sizeof(struct gameState));
    r = initializeGame(3, k, seed, &G); 
    G.handCount[p] = handCount;
    memcpy(G.hand[p], k, sizeof(int) * handCount);
    
    // call the refactored function again
    tributePlayed(card, &G, 2, choice2, choice3, handPos, &bonus, currentPlayer, nextPlayer, tributeRevealedCards);

    // continue testing the function
    assert(G.coins == 2);

    printf("Test completed!\n");
}
