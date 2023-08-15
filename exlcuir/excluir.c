////////////////////////////////////////////
// programa de lista duplamente encadeada //
////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////
// declaracao da estrutura do no //
///////////////////////////////////

struct no {
	int numero;
	struct no *anterior;
	struct no *proximo;
};

/////////////////////////////
// declaracao de variaveis //
////////////////////////////

struct no *cabeca = NULL;

//////////////////////////////////////
// funcao que insere um no na lista //
//////////////////////////////////////

void inserir(int numero) {
	// instanciacao da memoria
	struct no *novoNo = (struct no *) malloc (sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> anterior = NULL;
	novoNo -> proximo = NULL;
	
	if (cabeca == NULL) {
		// caso facil em que a lista esta vazia
		cabeca = novoNo;
	} else {
		// caso dificil em que a lista NAO esta vazia
		struct no *ultimo = cabeca;
		
		while(ultimo -> proximo != NULL) {
			ultimo = ultimo -> proximo;
		}
		
		ultimo -> proximo = novoNo;
		novoNo -> anterior = ultimo;
	}
}

////////////////////////////////////////
// funcao que imprime os nos da lista //
////////////////////////////////////////

void imprimir() {
	printf("===============\n");
	struct no *ponteiro = cabeca;
	
	while (ponteiro != NULL) {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	} 
}

//////////////////////
// funcao principal //
/////////////////////

int main() {
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	inserir(6);
	
	imprimir();
}


-------------------------------------------------------------------------------------------------------------------

////////////////////////////////////////////
// programa de Lista duplamente encadeada //
////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////
// declaracao da estrutura do no //
///////////////////////////////////

struct no {
	int numero;
	struct no *anterior;
	struct no *proximo;
};

/////////////////////////////
// declaracao de variaveis //
////////////////////////////

struct no *cabeca = NULL;

//////////////////////////////////////
// funcao que insere um no na lista //
//////////////////////////////////////

void inserir(int numero) {
	// instanciacao da memoria
	struct no *novoNo = (struct no *) malloc (sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> anterior = NULL;
	novoNo -> proximo = NULL;
	
	if (cabeca == NULL) {
		// caso facil em que a lista esta vazia
		cabeca = novoNo;
	} else {
		// caso dificil em que a lista NAO esta vazia
		struct no *ultimo = cabeca;
		
		while(ultimo -> proximo != NULL) {
			ultimo = ultimo -> proximo;
		}
		
		ultimo -> proximo = novoNo;
		novoNo -> anterior = ultimo;
	}
}

////////////////////////////////////////
// funcao que imprime os nos da lista //
////////////////////////////////////////

void imprimir() {
	printf("===============\n");
	struct no *ponteiro = cabeca;
	
	while (ponteiro != NULL) {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	} 
}

//////////////////////////////////////
// funcao que exclui um no na lista //
//////////////////////////////////////

void excluir(int numero) {
	struct no *ponteiro = cabeca;
	
	while (ponteiro != NULL) {
		if (ponteiro -> numero == numero) {
			// forcar a exclusao
			if (ponteiro == cabeca) {
				cabeca = cabeca -> proximo;
				cabeca -> anterior = NULL;
			} else if (ponteiro -> proximo == NULL) {
				// excluir  o ultimo
			}
			} else {
				// excluir no meio
				ponteiro -> proximo -> anterior = ponteiro -> anterior;
				ponteiro -> anterior -> proximo = ponteiro -> proximo;
			}
			
			free(ponteiro);
		}
		
		ponteiro = ponteiro -> proximo;
	}

//////////////////////
// funcao principal //
/////////////////////

int main() {
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	inserir(6);
	
	imprimir();
	
	excluir(1);
	excluir(3);
	excluir(3);
	excluir(6);
	
	imprimir();
	
}
