#include<stdio.h>
#include<stdlib.h>

///// estrutura no

struct no {
	int numero;
	struct no *anterior;
	struct no *proximo;

};

////////////variaveis

struct no *cabeca = NULL;

//////////fybcao que insere no na lista

void inserir(int numero){
	///instanciacao da memoria
	struct no *novoNo = (struct no*) malloc(sizeof (struct no));
	novoNo -> numero = numero;
	novoNo -> anterior = NULL;
	novoNo -> proximo = NULL;
	
	if (cabeca == NULL){
	//lista vazia
	cabeca = novoNo;
	} else {
		//lista nao vazia
		struct no *ultimo = cabeca;
		
		while (ultimo->proximo!=NULL){
			ultimo = ultimo -> proximo;
		}
		ultimo -> proximo = novoNo;
		novoNo -> anterior = ultimo;
	}
}

////imprimir

void imprimir(){
	printf("======================\n");
	
	struct no *ponteiro = cabeca;
	
	while(ponteiro != NULL) {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}



///execucao

int main (){
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	inserir(6);
	
	imprimir();
}
