// Unittest3.c
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
    int handCount = 3;
    int bonus = 0;
    int j = 0;
    int p = 0;
    int currentPlayer = 0;

    // set your card array
    int k[6] = { gold, minion, copper, copper, copper, copper };
    // declare the game state
    struct gameState G;

    printf("Begin test: minePlayed()\n");

    // set the state of your variables
    memset(&G, 23, sizeof(struct gameState));
    int r = initializeGame(2, k, seed, &G);
    G.handCount[p] = handCount;
    memcpy(G.hand[p], k, sizeof(int) * handCount);

    // call the refactored function
    minionPlayed(card, 0, 1, &G, handPos, &bonus, currentPlayer);
    
    // verify that your asserts pass, for the bugs your asserts may fail
    assert(G.coins == 2); // check a assert(some condition);

    // adjust the state of your variables to
    // comment on what this is going to test //
    memset(&G, 0, sizeof(struct gameState));
    r = initializeGame(3, k, seed, &G); 
    G.handCount[p] = handCount;
    memcpy(G.hand[p], k, sizeof(int) * handCount);
    
    // call the refactored function again
    minionPlayed(card, 1, 1, &G, handPos, &bonus, currentPlayer);

    // continue testing the function
    assert(G.coins == 0);
    assert(G.handCount[p] == 4);

    printf("Test completed!\n");
}
