#include <stdio.h>
#include <stdlib.h>

//////////////////PILHA///////////////

struct no{
	int numero;
	struct no *proximo;
};

//variaveis

struct no *cabeca = NULL;

////funcao de inserir um nana pilha////

void push(int numero){
	//instanciacao da memoria
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = NULL;
	cabeca = novoNo;
}

/// funcao que verifica o topo da pilha

int top() {
	int retorno = 0;
	
	if (cabeca != NULL) {
		retorno = cabeca -> numero;
	}
	
	return retorno;
}

//funcao que remove um da pilha

int pop(){
	int retorno = 0;
	
	if (cabeca != NULL) {
		retorno = cabeca -> numero;
		struct no *temp = cabeca;
		cabeca = cabeca -> proximo;
		free(temp);
	}
	
	return retorno;
}

//////////////////////////////////////////////////////




//////////inserir 1 na lista///////////

void inserir(int numero){
	//instanciacao de memory
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = cabeca;
	cabeca = novoNo;	
}
//////remover um no da fila ///////

int remover(){
	//variaveis
	struct no *ponteiro = cabeca;
	int retorno = 0;
	
	if (cabeca != NULL) {
		if (cabeca -> proximo == NULL) {
			retorno = cabeca -> numero;
			free(cabeca);
			cabeca = NULL;
		} else {
	
			//navegando ate o ultimo
			while (ponteiro -> proximo -> proximo != NULL) {
				ponteiro = ponteiro -> proximo;
			}
			retorno = ponteiro -> proximo -> numero;
			free(ponteiro -> proximo);
			ponteiro -> proximo = NULL;
	
		}
	}
	return retorno;
}


///funcao principal de execute///

int main (){
	printf("%d\n", pop());
	printf("================\n");
	
	inserir(1);
	printf("%d\n", pop());
	printf("================\n");
	
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("================\n");
}
