CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)
	
cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o -coverage -fpic -lm $(CFLAGS)
			
cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o -coverage -fpic -lm $(CFLAGS)
	
cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o -coverage -fpic -lm $(CFLAGS)
	
cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o -coverage -fpic -lm $(CFLAGS)

#unittest1: unittest1.c dominion.o rngs.o
#	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)

#unittest for 2 and 4 don't really compile which is why I block them out plus they aren't required for this homework
#unittest2: unittest2.c dominion.o rngs.o
#	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

#unittest3: unittest3.c dominion.o rngs.o
#	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)

#unittest4: unittest4.c dominion.o rngs.o
#	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)			

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o	
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o -coverage -fpic -lm $(CFLAGS)

randomtest2: randomtest2.c dominion.o rngs.o
	gcc -o randomtest2 -g randomtest2.c dominion.o rngs.o  -coverage -fpic -lm  $(CFLAGS)

randomtest3: randomtest3.c dominion.o rngs.o
	gcc -o randomtest3 -g randomtest3.c dominion.o rngs.o  -coverage -fpic -lm $(CFLAGS)
			
testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)


runtests: testDrawCard cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtest2 randomtest3	
	./testDrawCard &> unittestresult.out
	#/unittest1 >> unittestresult.out
	#/unittest3 >> unittestresult.out
	./cardtest1 >> cardtest1.out
	./cardtest2 >> cardtest2.out
	./cardtest3 >> cardtest3.out
	./cardtest4 >> cardtest4.out
	./randomtestadventurer >> randomtestadventurer.out
	./randomtest2 >> randomtest2.out
	./randomtest3 >> randomtest3.out
	gcov randomtestadventurer.c >> radnomtestadventurer.out
	gcov randomtest2.c >> radnomtest2.out
	gcov randomtest3.c >> radnomtest4.out
	gcov cardtest1.c >> cardtest1.out
	gcov cardtest2.c >> cardtest2.out
	gcov cardtest3.c >> cardtest3.out
	gcov cardtest4.c >> cardtest4.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	cat



player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard randomtestadventurer randomtest2 randomtest3 cardtest1 cardtest2 cardtest3 cardtest4

clean:
	rm -f *.o playdom.exe playdom player player.exe cardtest1 cardtest1.exe cardtest2 cardtest2.exe cardtest3 cardtest3.exe cardtest4 cardtest4.exe  randomtestadventurer randomtestadventurer.exe randomtest2 randomtest2.exe  randomtest3 randomtest3.exe *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
