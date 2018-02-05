#include "dominion.h"
#include <stdio.h>
#include <assert.h>



int main () {
	int i = 0;
	int r = 0;
	for ( i = 0; i < 26; i++){
		r = getCost(i);
		if(i == 0){	
			assert(r == 0);
		}else if(i == 1){	
			assert(r == 2);
		}else if(i == 2){	
			assert(r == 5);
		}else if(i == 3){	
			assert(r == 8);
		}else if(i == 4){	
			assert(r == 0);
		}else if(i == 5){	
			assert(r == 3);
		}else if(i == 6){	
			assert(r == 6);
		}else if(i == 7){	
			assert(r == 6);
		}else if(i == 8){	
			assert(r == 5);
		}else if(i == 9){	
			assert(r == 4);
		}else if(i == 10){	
			assert(r == 4);
		}else if(i == 11){	
			assert(r == 5);
		}else if(i == 12){	
			assert(r == 4);
		}else if(i == 13){	
			assert(r == 4);
		}else if(i == 14){	
			assert(r == 3);
		}else if(i == 15){	
			assert(r == 4);
		}else if(i == 16){	
			assert(r == 3);
		}else if(i == 17){	
			assert(r == 5);
		}else if(i == 18){	
			assert(r == 3);
		}else if(i == 19){	
			assert(r == 5);
		}else if(i == 20){	
			assert(r == 3);
		}else if(i == 21){	
			assert(r == 4);
		}else if(i == 22){	
			assert(r == 2);
		}else if(i == 23){	
			assert(r == 5);
		}else if(i == 24){	
			assert(r == 4);
		}else if(i == 25){	
			assert(r == 4);
		}else if(i == 26){	
			assert(r == 4);
		}
	}
	return 0;
}
