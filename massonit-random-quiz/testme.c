#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//creates a random char 
char inputChar(){
	char randChar = ' ';
	int counter = 0;
	int randNum = 0;
	srand(time(NULL));
	const char charaset[] = "[({ax})] ";
	randNum = rand() % (int) (sizeof charaset - 1);
	randChar = charaset[randNum];
	return randChar;
}

//creates random array full of random string values
char *inputString(){
	int length = 6;
	static char str[256];
	int n = 0;
	const char charset[]="rest";
	if (length){
		length--;
		for (n = 0; n < length; n++){
			int key = rand() % (int) (sizeof charset - 1);
			str[n] = charset[key];
		}
		str[length] = '\0';
	}
	return str;
}
			
void testme(){
   //becuase I got segfaults when this equalled zero. Don't ask me why.
   int tcCount;
   char *s;
   char c;
   int state = 0;
   while(1){
  	 tcCount++;
  	 c = inputChar();
	 s = inputString();
   	 printf("Iteration %d: c = %c, s = %s , state = %d\n",tcCount, c , s, state);
	 if (c == '[' && state == 0) state = 1;
     if (c == '(' && state == 1) state = 2;
     if (c == '{' && state == 2) state = 3;
     if (c == ' '&& state == 3) state = 4;
     if (c == 'a' && state == 4) state = 5;
     if (c == 'x' && state == 5) state = 6;
     if (c == '}' && state == 6) state = 7;
     if (c == ')' && state == 7) state = 8;
     if (c == ']' && state == 8) state = 9;
     if (s[0] == 'r' && s[1] == 'e'
        && s[2] == 's' && s[3] == 'e'
        && s[4] == 't' && s[5] == '\0'
        && state == 9)
	{
      printf("error ");
      exit(200);
    }
	
  }
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	testme();
	return 0;
}	
