#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_TEST 100

int main(){
		int k[10] = { adventurer, smithy, gardens, village, steward, minion, mine, remodel, feast, council_room, sea_hag };
		int i, j, players, seed, player = 0, retVal = 0, count = 0, failures = 0, success = 0;
		struct gameState * Gstate;
		for( i = 0, failures = 0, sucess = 0; i < NUM_TEST; i++){
			players = rand() % 4;
			seed = rand();
			Gstate = malloc(sizeof(struct gameState));
			initalizeGame(players, k, seed, Gstate);
			Gstate->deckCount[player] = rand()% MAX_DECK;
			Gstate->discardCount[player] = rand()% MAX_DECK;
			Gstate->discardCount[player] = rand()% MAX_HAND;
			
			count = 0;
			for( j = 0; j <gState->handCount[player]; j++){
					if((Gstate->hand[player][j] == copper){
						count++;
					}else if((Gstate->hand[player][j] == gold){
						count++;
					}else if((Gstate->hand[player][j] == gold){
						count++;
					}
			}
			
			cardEffect(adventurer, 1, 1, 1, Gstate, 0, 0);
			
						for( j = 0; j <gState->handCount[player]; j++){
					if((Gstate->hand[player][j] == copper){
						count--;
					}else if((Gstate->hand[player][j] == gold){
						count--;
					}else if((Gstate->hand[player][j] == gold){
						count--;
					}
			}
			
			
			if(count < 0){
				sucess++;
			}else {
				faliures++;
			}
			
			free(Gstate);
			printf("Completed Test #%d\n", i);
		}
	
}