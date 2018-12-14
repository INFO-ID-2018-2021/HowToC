#include <stdio.h>
#include <stdlib.h>

typedef struct Nodes{
	struct Nodes* next;
	struct Nodes* prev;
	int value;
} Node;

void main(){
	Node *inceputLista = NULL, *nodulCurent;
	printf("Sa se introduca numere... La -1 se opreste.\n");

	int numarCurent;
	do{
		scanf("%d",&numarCurent);
		if(inceputLista==NULL){
			inceputLista = (Node*)malloc(sizeof(Node));
			inceputLista->value = numarCurent;
			inceputLista->next = NULL;
			inceputLista->prev = NULL;
			nodulCurent = inceputLista;
		}
		else{
			Node* nodNou = (Node*)malloc(sizeof(Node));
			nodNou->value = numarCurent;
			nodNou->next = NULL;
			nodNou->prev = nodulCurent;
			nodulCurent->next = nodNou;
			nodulCurent = nodNou;
		}		
	}while(numarCurent!=-1);

	Node* sfarsitLista = nodulCurent;
	printf("Afisare lista obtinuta de la cap la coada:\n");
	nodulCurent = inceputLista;

	while(nodulCurent != NULL && nodulCurent->value!=-1){
		printf("%d ", nodulCurent->value);
		nodulCurent = nodulCurent->next;
	}
	printf("\nAfisare lista obtinuta de la coada la cap:\n");
	nodulCurent = sfarsitLista->prev;
	while(nodulCurent != NULL && nodulCurent->value!=-1){
		printf("%d ", nodulCurent->value);
		nodulCurent = nodulCurent->prev;
	}

	printf("\nDONE\n");
}