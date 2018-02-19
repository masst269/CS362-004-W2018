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
		int count = 0;
		int actions = 2;
		
		
		for( i = 0, failures = 0, sucess = 0; i < NUM_TEST; i++){
			players = rand() % 4;
			seed = rand();
			Gstate = malloc(sizeof(struct gameState));
			initalizeGame(players, k, seed, Gstate);
			Gstate->deckCount[player] = rand()% MAX_DECK;
			Gstate->discardCount[player] = rand()% MAX_DECK;
			Gstate->handCount[player] = rand()% MAX_HAND;
			
			for(i = 0; i < Gstate->handCount[player]; j++){
				count++:
			}
			cardEffect(adventurer, 1, 1, 1, Gstate, 0, 0);
		
			count++;
			
			if(count == Gstate->handCount[player] ){
				if(gState->numActions == actions){
					sucess++;
				}else{
					failures++;
				}
			}else(count != Gstate->handCount[player]){
				faliures++;
			}
			
			free(Gstate);
			printf("Completed Test #%d\n", i);
		}
	
}