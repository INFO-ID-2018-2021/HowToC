#include <stdio.h>
#include <stdlib.h>

typedef struct Nodes{
	struct Nodes* urmatorul;
	int valoare;
} Nod;

Nod* ConstructorNodDinamic(int valoare){
	Nod* n = (Nod*)malloc(sizeof(Nod));
	n->valoare = valoare;
	n->urmatorul = NULL;
	return n; 
}

Nod* ConstructorNodStatic(int valoare){
	Nod n;
	n.valoare=valoare;
	n.urmatorul=NULL;
	return &n;
}

void AdaugareNod(Nod* nodulCurent, int valoareDeAdaugat){
	Nod* nodDeAdaugat = ConstructorNodDinamic(valoareDeAdaugat);
	nodulCurent->urmatorul = nodDeAdaugat;
}

Nod* NodulUrmator(Nod* nodulCurent){
	return nodulCurent->urmatorul;
}

void main(){
	Nod* inceputLista = NULL;
	printf("Sa se introduca numere... La -1 se opreste.\n");
	int numarCurent;
	Nod* nodulCurent;
	do{
		scanf("%d",&numarCurent);
		if(inceputLista==NULL){
			inceputLista = ConstructorNodDinamic(numarCurent);
			nodulCurent = inceputLista;
		}
		else{
			AdaugareNod(nodulCurent,numarCurent);
			nodulCurent = NodulUrmator(nodulCurent);
		}		
	}while(numarCurent!=-1);

	printf("Afisare lista obtinuta:\n");
	nodulCurent = inceputLista;

	while(nodulCurent != NULL && nodulCurent->valoare!=-1){
		printf("%d ", nodulCurent->valoare);
		nodulCurent = NodulUrmator(nodulCurent);
	}
	printf("\nDONE\n");

}