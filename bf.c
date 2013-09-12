#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char* argv[] ){

	FILE* s = fopen(argv[1],"r");
	FILE* o = fopen("a.c","w");
	fprintf(o, "#include <stdio.h>\n");
	fprintf(o, "#include <stdlib.h>\n");
	fprintf(o, "int main( void ){\n");
	fprintf(o, "\tchar code[] = \"");


	for(;;){

		char p = fgetc(s);
		if(p == EOF){
			break;
		}
		
		if(p != '\n'){
			fprintf(o,"%c",p);
		}
		
		
	}
	
	/* Close files */

	fclose(s);

	fprintf(o, "\";\n\treturn 0;\n}");

	fclose(o);
	
	/* Compile */
	
	char command[60];
	strcat(command,"gcc a.c -o ");
	strcat(command,argv[2]);
	system(command);
	
	//remove("a.c");

	return 0;
}
