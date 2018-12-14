/*
** Ca lista sa fie circulara
** Ultimul nod trebuie sa aiba legatura cu primul nod
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Nodes{
	struct Nodes* urmatorul;
	int valoare;
} Nod;

void main(){
	Nod *inceputLista = NULL, *nodulCurent;
	printf("Sa se introduca numere... La -1 se opreste.\n");

	int numarCurent;
	do{
		scanf("%d",&numarCurent);
		if(inceputLista==NULL){
			inceputLista = (Nod*)malloc(sizeof(Nod));
			inceputLista->valoare = numarCurent;
			inceputLista->urmatorul = NULL;
			nodulCurent = inceputLista;
		}
		else{
			Nod* nodNou = (Nod*)malloc(sizeof(Nod));
			nodNou->valoare = numarCurent;
			nodNou->urmatorul = NULL;
			nodulCurent->urmatorul = nodNou;
			nodulCurent = nodNou;
		}		
	}while(numarCurent!=-1);

	printf("Afisare lista obtinuta:\n");
	nodulCurent = inceputLista;

	while(nodulCurent != NULL && nodulCurent->valoare!=-1){
		printf("%d ", nodulCurent->valoare);
		nodulCurent = nodulCurent->urmatorul;
	}
	printf("\nDONE\n");
}