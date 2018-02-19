#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1


int main () {

  int i, n, r, p;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;
  int discardcount = 0;
  int handcount = 0;
  int deckcount = 0;
  int supply = 5;
  printf ("Testing drawCard.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    p = floor(Random() * 2);
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    checkDrawCard(p, &G);
  }

  printf ("ALL TESTS OK\n");

  exit(0);

  printf ("SIMPLE FIXED TESTS.\n");
  for (p = 0; p < 2; p++) {
	  r = initializeGame(2, k, 1, &G);
	  G.deckCount[p] = deckCount;
	  memset(G.deck[p], 0, sizeof(int) * MAX_DECK);
	  G.discardCount[p] = discardCount;
	  memset(G.discard[p], 0, sizeof(int) * MAX_DECK);
	  G.handCount[p] = handcount;
	  memset(G.hand[p], 0, sizeof(int) * MAX_HAND);
	  ToFlag=1;
	  gainCard(supply,p &G,ToFlag);
      printf("G.deck = %d, expected = %d\n", G.deck, deckcount++ );
	   assert(G.deck == deckcount ++); // check if the number of coins is correct
	   supply--;
	  ToFlag=2;
	  gainCard(supply,p &G,ToFlag);
      printf("G.hand[p] = %d, expected = %d\n", G.hand, handcount++ );
	   assert(G.hand[p] == handcount ++); // check if the number of coins is correct
	   	   supply--;
	  ToFlag=3;
	  gainCard(supply,p &G,ToFlag);
      printf("G.discard[p] = %d, expected = %d\n", G.discard[p], discardcount++ );
	   assert(G.discard[p] == discardcount ++); // check if the number of coins is correct	
	}
      }
    }
  }

  return 0;
}
