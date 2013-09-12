#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char* argv[] ){

	int toCFlag = 0;
	int v = 0;
	for(v; v < argc; v++){
		if(argv[v] == "-c"){
			toCFlag = 1;
		}
	}
	
	FILE* s = fopen(argv[1],"r");
	FILE* o = fopen("a.c","w");
	fprintf(o, "#include <stdio.h>\n");
	fprintf(o, "#include <stdlib.h>\n");
	fprintf(o, "#include <string.h>\n");
	fprintf(o, "int main( void ){\n");
	fprintf(o, "\tchar* codep = \"");
	
	int i = 0;

	for(;;){

		char p = fgetc(s);
		if(p == EOF){
			break;
		}
		
		if(p != '\n'){
			fprintf(o,"%c",p);
			i++;
		}
		
		
	}
	
	/* Close files */

	fclose(s);

	fprintf(o, "\";\n\tchar* mem = (char*) malloc(sizeof(char) * 600);");
	fprintf(o, "\n\tint i; // instruction pointer");
	fprintf(o, "\n\tchar code[%d];", i);
	fprintf(o, "\n\tstrcpy(code,codep);");
	fprintf(o, "\n\tint ptr = 0; // memory pointer");
	fprintf(o, "\n\tfor(i = 0; i < %d; i++){", i);
	fprintf(o, "\n\t\tif(code[i] == '>') ptr++;");
	fprintf(o, "\n\t\tif(code[i] == '<') ptr--;");
	fprintf(o, "\n\t\tif(code[i] == '+') *(mem + ptr) = *(mem + ptr) + 1;");
	fprintf(o, "\n\t\tif(code[i] == '-') *(mem + ptr) = *(mem + ptr) - 1;");
	fprintf(o, "\n\t\tif(code[i] == '.') putchar(*(mem + ptr));");
	fprintf(o, "\n\t\tif(code[i] == ',') *(mem + ptr) = getchar();");
	fprintf(o, "\n\t\tif(code[i] == '['){"); 
	fprintf(o, "\n\t\t\tif(*(mem + ptr) == 0){");
	fprintf(o, "\n\t\t\t\twhile((code[i] != ']')){");
	fprintf(o, "\n\t\t\t\t\ti++;");
	fprintf(o, "\n\t\t\t\t}");
	fprintf(o, "\n\t\t\t\ti++;");
	fprintf(o, "\n\t\t\t}"); 
	fprintf(o, "\n\t\t}");
	fprintf(o, "\n\t\tif(code[i] == ']'){"); 
	fprintf(o, "\n\t\t\tif(*(mem + ptr) != 0){");
	fprintf(o, "\n\t\t\t\twhile((code[i] != '[')){");
	fprintf(o, "\n\t\t\t\t\ti--;");
	fprintf(o, "\n\t\t\t\t}");
	fprintf(o, "\n\t\t\t\ti--;");
	fprintf(o, "\n\t\t\t}"); 
	fprintf(o, "\n\t\t}");	
	fprintf(o, "\n\t}");
	fprintf(o, "\n\treturn 0;\n}");

	fclose(o);
	
	/* Compile */
	
	char command[60];
	strcat(command,"gcc a.c -o ");
	strcat(command,argv[2]);
	system(command);

	if(toCFlag == 1){
		remove("a.c");
	}

	return 0;
}
