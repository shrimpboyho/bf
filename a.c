#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main( void ){
	char* codep = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
	char* mem = (char*) malloc(sizeof(char) * 600);
	int i; // instruction pointer
	char code[111];
	strcpy(code,codep);
	int ptr = 0; // memory pointer
	for(i = 0; i < 111; i++){
		if(code[i] == '>') ptr++;
		if(code[i] == '<') ptr--;
		if(code[i] == '+') *(mem + ptr) = *(mem + ptr) + 1;
		if(code[i] == '-') *(mem + ptr) = *(mem + ptr) - 1;
		if(code[i] == '.') putchar(*(mem + ptr));
		if(code[i] == ',') *(mem + ptr) = getchar();
		if(code[i] == '['){
			if(*(mem + ptr) == 0){
				while((code[i] != ']')){
					i++;
				}
				i++;
			}
		}
		if(code[i] == ']'){
			if(*(mem + ptr) != 0){
				while((code[i] != '[')){
					i--;
				}
				i--;
			}
		}
	}
	return 0;
}