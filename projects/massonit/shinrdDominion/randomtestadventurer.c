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
		int i, j, m, players, seed, player = 0, cost = 0, count = 0, count1 = 0, count2 = 0, count3 = 0, failures = 0, fail = 0, success = 0;
		struct gameState G;
		srand(time(0));
		printf("Random Testing for the Adventurer\n");
		//The randomness comes the generating numbers for the deck, hand, discard, and player count
		for( i = 0, failures = 0, success = 0; i < NUM_TEST; i++){
			players = rand() % 4;
			seed = rand();
			fail = 0;
			count = 0;
			cost = 0;
			initializeGame(players, k, seed, &G);
			count3 = rand() % MAX_DECK;
			G.deckCount[player] = count3;
			count2 = rand() % MAX_DECK;
			G.discardCount[player] = count2;
			count1 = rand() % MAX_HAND;
			G.handCount[player] = count1;
			for(j = 0; j < G.handCount[player]; j++){
				if(G.hand[player][j] == gold || G.hand[player][j] == copper || G.hand[player][j] == silver){
					cost++;	
				}
			}
			count = count1+2;
			m = cardEffect(adventurer, 1, 1, 1, &G, 0, 0);
			for(j = 0; j < count; j++){
				if(G.hand[player][j] == gold || G.hand[player][j] == copper || G.hand[player][j] == silver){
					cost--;	
				}
			}
			if(G.handCount[player] != (count1+1)){
				fail++;
			}
			if(G.discardCount[player] <= (count2)){
				fail++;
			}
			if(G.deckCount[player] >= (count3)){
				fail++;	
			}
			if(m != 0){
				fail++;
			}
			if(cost >= 0){
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
	

