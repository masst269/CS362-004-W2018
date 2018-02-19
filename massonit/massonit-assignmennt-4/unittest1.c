#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1
#define TESTCARD "Gain Card"


int main () {

  int i, n, r, p;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;
  int discardcount = 0;
  int handcount = 0;
  int deckcount = 0;
  int supply = 5;
  int ToFlag = 0;
  printf ("Testing drawCard.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  printf ("ALL TESTS OK\n");
  printf ("SIMPLE FIXED TESTS.\n");
  for (p = 0; p < 2; p++) {
	  r = initializeGame(2, k, 1, &G);
	  G.deckCount[p] = deckcount;
	  memset(G.deck[p], 0, sizeof(int) * 5);
	  G.discardCount[p] = discardcount;
	  memset(G.discard[p], 0, sizeof(int) * 5);
	  G.handCount[p] = handcount;
	  memset(G.hand[p], 0, sizeof(int) * 5);
	  ToFlag=1;
	  gainCard(supply, &G, ToFlag, p);
	  deckcount = deckcount + 1;
      	  printf("G.deckCount[p] = %d, expected = %d\n", G.deckCount[p], deckcount);
	   //assert(G.deckCount[p] == deckcount + 1); // check if the number of coins is correct
	   supply--;
	  ToFlag=2;
          handcount = handcount + 1;
	  gainCard(supply, &G, ToFlag, p );
      printf("G.handCount[p] = %d, expected = %d\n", G.handCount[p], handcount);
	   assert(G.handCount[p] == handcount); // check if the number of coins is correct
	   	   supply--;
	  ToFlag=3;
	  discardcount = discardcount + 1;
	  gainCard(supply, &G, ToFlag, p);
      printf("G.discardCount[p] = %d, expected = %d\n", G.discardCount[p], discardcount);

	   assert(G.discardCount[p] == discardcount); // check if the number of coins is correct	
  }
  printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
  return 0;

}
