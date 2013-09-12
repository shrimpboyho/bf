#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char* argv[] ){

	FILE* s = fopen(argv[1],"r");

	for(;;){

		char p = fgetc(s);
		if(p == EOF){
			break;
		}
		printf("%c",p);
	}
	fclose(s);

	return 0;
}
