#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define NUM_TEST 500

int main(){
		int k[10] = { adventurer, smithy, gardens, village, steward, minion, mine, remodel, council_room, sea_hag};
		int i, m, players, seed, player = 0, count1 = 0, count2 = 0, count3 = 0, failures = 0, fail = 0, success = 0;
		struct gameState G;
		srand(time(0));
		printf("Random Test for Village\n");
		//The randomness comes the generating numbers for the deck, hand, discard, and player count
		for( i = 0, failures = 0, success = 0; i < NUM_TEST; i++){
			players = rand() % 4;
			seed = rand();
			initializeGame(players, k, seed, &G);
			count3 = rand() % MAX_DECK;
			G.deckCount[player] = count3;
			count2 = rand() % MAX_DECK;
			G.discardCount[player] = count2;
			count1 = rand() % MAX_HAND;
			G.handCount[player] = count1;
				
			m = cardEffect(village, 1, 1, 1, &G, 0, 0);
			if(G.handCount[player] != (count1)){
				fail++;
			}
			if(G.numActions != 2){
				fail++;	
			}
			if(G.discardCount[player] != (count2+1)){
				fail++;
			}
			if(G.deckCount[player] != (count3-1)){
				fail++;	
			}
			if(m != 0){
				fail++;
			}
			if(fail > 0){
				failures++;
			}else{
				success++;
			}
			printf("Completed Test #%d\n", i);
		}
		printf("\n");
		printf("State: %d failures and %d sucesses\n", failures, success);
		printf("%d game run\n", NUM_TEST);
		return 0;
} 
	

