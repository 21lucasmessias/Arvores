#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

typedef struct tree{
	int chave;
	struct tree *dir;
	struct tree *esq;
}Tree;

Tree *alocar(){
	Tree *aux = (Tree *)malloc(sizeof(Tree));
	if(!aux){
		printf("Erro ao alocar");
		return NULL;
	}
	aux->dir = NULL;
	aux->esq = NULL;
	return aux;
}

void adicionar(Tree **pai, int chave){
	assert(pai);
	
	Tree *aux = alocar();
	if(!aux) return;
	aux->chave = chave;

	if(!*pai){
		*pai = aux;
	}else{
		Tree *andar = *pai;
		while(andar){
			if(andar->chave < chave){
				if(!andar->dir){
					andar->dir = aux;
					return;
				}
				andar = andar->dir;
			}else{
				if(!andar->esq){
					andar->esq = aux;
					return;
				}
				andar = andar->esq;
			}
		}
	}
}

void mostrar(Tree *pai, int altura){
	if(!pai) return;
	while(pai->esq){
		pai = pai->esq;
	}
	printf("%d\n", pai->chave);
}


void main(){
	Tree *pai = NULL;
	int altura = 0;
	int chave;
	srand(time(0));

	for(int i = 0 ; i < 20 ; i++){
		chave = rand() % 100 + 1;
		printf("adicionando %d\n", chave);
		adicionar(&pai, chave);
		altura++;
	}
	mostrar(pai, altura);
}