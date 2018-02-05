#include "dominion.h"
#include <stdio.h>
#include <assert.h>



int main () {
	int i = 0;
	int r = 0;
	printf("Beginging Testing for GetCost():\n");
	for ( i = 0; i < 26; i++){
		r = getCost(i);
		if(i == 0){
			printf("getCost = %d: Actual Cost %d\n", r, 0);
			assert(r == 0);
		}else if(i == 1){
			printf("getCost = %d: Actual Cost %d\n", r, 2);
			assert(r == 2);
		}else if(i == 2){	
			printf("getCost = %d: Actual Cost %d\n", r, 5);
			assert(r == 5);
		}else if(i == 3){
			printf("getCost = %d: Actual Cost %d\n", r, 8);
			assert(r == 8);
		}else if(i == 4){
			printf("getCost = %d: Actual Cost %d\n", r, 0);
			assert(r == 0);
		}else if(i == 5){
			printf("getCost = %d: Actual Cost %d\n", r, 3);
			assert(r == 3);
		}else if(i == 6){
			printf("getCost = %d: Actual Cost %d\n", r, 6);
			assert(r == 6);
		}else if(i == 7){
			printf("getCost = %d: Actual Cost %d\n", r, 6);
			assert(r == 6);
		}else if(i == 8){
			printf("getCost = %d: Actual Cost %d\n", r, 5);
			assert(r == 5);
		}else if(i == 9){	
			printf("getCost = %d: Actual Cost %d\n", r, 4);
			assert(r == 4);
		}else if(i == 10){	
			printf("getCost = %d: Actual Cost %d\n", r, 4);
			assert(r == 4);
		}else if(i == 11){	
			printf("getCost = %d: Actual Cost %d\n", r, 5);
			assert(r == 5);
		}else if(i == 12){	
			printf("getCost = %d: Actual Cost %d\n", r, 4);
			assert(r == 4);
		}else if(i == 13){	
			printf("getCost = %d: Actual Cost %d\n", r, 4);
			assert(r == 4);
		}else if(i == 14){	
			printf("getCost = %d: Actual Cost %d\n", r, 3);
			assert(r == 3);
		}else if(i == 15){
			printf("getCost = %d: Actual Cost %d\n", r, 4);
			assert(r == 4);
		}else if(i == 16){
			printf("getCost = %d: Actual Cost %d\n", r, 3);
			assert(r == 3);
		}else if(i == 17){	
			printf("getCost = %d: Actual Cost %d\n", r, 5);
			assert(r == 5);
		}else if(i == 18){	
			printf("getCost = %d: Actual Cost %d\n", r, 3);
			assert(r == 3);
		}else if(i == 19){
			printf("getCost = %d: Actual Cost %d\n", r, 5);
			assert(r == 5);
		}else if(i == 20){
			printf("getCost = %d: Actual Cost %d\n", r, 3);
			assert(r == 3);
		}else if(i == 21){
			printf("getCost = %d: Actual Cost %d\n", r, 4);
			assert(r == 4);
		}else if(i == 22){
			printf("getCost = %d: Actual Cost %d\n", r, 2);
			assert(r == 2);
		}else if(i == 23){
			printf("getCost = %d: Actual Cost %d\n", r, 5);
			assert(r == 5);
		}else if(i == 24){
			printf("getCost = %d: Actual Cost %d\n", r, 4);
			assert(r == 4);
		}else if(i == 25){
			printf("getCost = %d: Actual Cost %d\n", r, 4);
			assert(r == 4);
		}else if(i == 26){
			printf("getCost = %d: Actual Cost %d\n", r, 4);
			assert(r == 4);
		}
	}
	printf("Finished testing);
	return 0;
}
