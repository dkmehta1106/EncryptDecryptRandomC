#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{

	srand(time(0)); // Use the current time as the seed for random generator

	if (argc != 2)
	{
		fprintf(stderr, "Please invoke as %s <key>\n", argv[0]);
		return 1; // Indicate something went wrong
	}
	char *key=argv[1];
	int nextChar = getchar();
	int convert[2][98]; 
	convert[0][0] = 9;
	convert[0][1] = 10;
	convert[1][0] = 9;
	convert[1][1] = 10;
	for (int i = 32; i < 128; ++i) {
		convert[0][i-30] = i;
		convert[1][i-30] = 0;
	}
	for (int i = 32; i < 128; ++i) {
		int temp = 32+(rand()%96);
		int flag = 1;
		for(int j = 0; j < (i-30); ++j) {
			if (convert[1][j] == temp) {
				flag = 0;
				break;
			}
		}

		if(flag == 1) {
			convert[1][i-30] = temp;
		}
		else {
			--i;
		}
	}
	
	while (nextChar != EOF)
	{
		int deCoded;
		int temp = nextChar;
		// if (((temp!=9) || (temp!=10)) && temp < 32) {
		// 	temp = temp + 32;
		// }

		for (int i = 0; i < 98; ++i) {
			if (convert[0][i] == temp) {
				deCoded = convert[1][i];
				break;
			}
		}
		putchar(deCoded);
		/* TODO:
			Using the key, write an decoded character to standard out
			For example, if you decode nextChar and save it in variable deCoded,
			You can use: putchar(deCoded);
		*/
		nextChar = getchar();
	}
	return 0; // Indicate nothing went wrong
}
