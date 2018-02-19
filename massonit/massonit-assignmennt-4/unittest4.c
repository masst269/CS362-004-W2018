#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1



int main () {
  int a = 5;
  int b = 4;
  int d = 5;
  int c = 0;
  c = compare(a, b);
  assert(c == 1);
  c = compare(b, a)
  assert(c == -1);
  c = compare(a, d);
  assert(c == 0); 
  return 0;
}
