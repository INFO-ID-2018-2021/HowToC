#include <stdio.h>

void main(){
	char nume[1000];
	int varsta;

	printf("Salut! Numele meu este FMIBOT. Cum te numesti?\n");
	scanf("%s", nume);	
	printf("Salut %s!\n", nume);

	printf("\n");

	printf("Cati ani ai?\n");
	scanf("%d", &varsta);
	printf("Multi inainte! Sper sa ajung si eu la venerabila varsta de %d ani\n",varsta);
}