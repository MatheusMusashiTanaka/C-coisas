//////estrutura no////////////
#include <stdio.h>
#include <stdlib.h>

struct no {
	int numero;
	struct no *proximo;

};


/////////declaracao de variaveis/////////

struct no *cabeca;



/////////insere um no na lista//////////

void inserir (int parametroNumero) {
	////criando uma nova no
	struct no *novoNo = NULL;
	novoNo = (struct no *) malloc(sizeof(struct no *));
	novoNo -> numero = parametroNumero;
	novoNo -> proximo = NULL;	
	if (cabeca == NULL)	{
		/////////vazio
	cabeca = novoNo;
    } else {
    	////////procurar ultimo elemento da struct
    	struct no *ponteiro = cabeca;
    	while (ponteiro -> proximo != NULL){
    		ponteiro = ponteiro -> proximo;
		}
			// apontar para uma nova no
	ponteiro -> proximo = novoNo;
	}


}


void imprimir() {
	struct no *ponteiro = cabeca;
	
	while (ponteiro != NULL) {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}


void remover(int parametronumero){
	struct no*ponteiroAnterior;
	struct no*ponteiroExcluir;	
	
	if (cabeca != NULL){
		if (cabeca -> numero == parametronumero){
			ponteiroExcluir=cabeca;
			cabeca = cabeca -> proximo;
			free(ponteiroExcluir);
		} else {
			ponteiroAnterior = cabeca;
			while ((ponteiroAnterior != NULL) && (ponteiroAnterior -> numero != parametronumero)){
				ponteiroAnterior = ponteiroAnterior -> proximo;
			}
			if (ponteiroAnterior != NULL){
				ponteiroExcluir = ponteiroAnterior -> proximo;
				ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
				free(ponteiroExcluir);
			}
		}
	}
}

///////////funçao principal principal////////////////

int main() {
	for (int i=0; i<10 ; i++){
		inserir(i);
	}
	
	imprimir();
	
	
	remover(3);
	
	imprimir();
	
	
	
}
