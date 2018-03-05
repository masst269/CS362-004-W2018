#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion_helpers.h"

int main (int argc, char** argv) {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int  j = 0;
    int handpos = 0, bonus = 0;
    //int seed = 1000;
    int thisPlayer = 0;
	struct gameState G, testG;
	int found = 0;
	int remove;
	
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			remodel, tribute, smithy, council_room};
	
    printf("starting testing for adventurer card\n");
		initializeGame(2, k, 2, &G);
		G.hand[thisPlayer][0] = adventurer;
		G.hand[thisPlayer][1] = copper;
		G.hand[thisPlayer][2] = duchy;
		G.hand[thisPlayer][3] = estate;
		G.hand[thisPlayer][4] = gold;
		for (j=0; j<G.handCount[thisPlayer]; j++) {
			int revealed = G.hand[thisPlayer][j];
			if (revealed == copper || revealed == silver || revealed == gold){
                		//printf("found coin\n");
               			 found++;
            		}	
			if (found == 2){
               			 break;
            		}else{
				remove++;
			}
		}		
		memcpy(&testG, &G, sizeof(struct gameState));
		cardEffect(adventurer, 1, 0, 0, &testG, handpos, &bonus);
		xtraCoins = found;
		newCards = found;
		discarded = remove + 1;
		printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
		printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
		printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
		assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
		assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
		assert(testG.coins == G.coins + xtraCoins);
	return 0;
}


