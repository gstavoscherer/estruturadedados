#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
	int dado;
	struct Pilha* prox;
}Pilha;

Pilha* inserePilha(Pilha* p, int dado){
	if(p == NULL){
		p = malloc(sizeof(Pilha));
		p->dado = dado;
		p->prox = NULL;
		
		return p;			
	}
	else{
		Pilha* novo = malloc(sizeof(Pilha));
		novo->dado = dado;
		novo->prox = p;
		
		return novo;
	}

	
}
Pilha* removePilha(Pilha* p){
		if(p == NULL){
			printf("Não tem nada aqui ainda!\n");
			return p;	
		}
		else{
			Pilha*temp = p->prox;
			free(p);
			
			return temp;	
		}
}
void imprimePilha(Pilha* p){
	Pilha* temp = p;
	while(temp != NULL){
		printf("%d -> ",temp->dado);
		temp = temp->prox;	
	}
	printf("NULL\n");
	
}
int main(){
	Pilha* pilha;
	pilha = NULL;
	int opcao, dada;
	do{
		printf("1.Insira o valor a ser adicionado na Pilha.\n");
		printf("2.Remover valor da Pilha.\n");
		printf("3.Imprimir Pilha.\n");
		printf("0.Sair.\n");
		scanf("%i",&opcao);
		switch(opcao){
			case 1:
				printf("Digite o valor a ser inserido: \n");
				scanf("%d",&dada);
				pilha = inserePilha(pilha, dada);
				break;
			
			case 2:
				printf("Item removido!\n");
				pilha = removePilha(pilha);
				break;
			case 3:
				imprimePilha(pilha);
				break;
			default:
				printf("Insira uma opção válida!\n");
				break;
		}
		
	}while(opcao != 0);
		
	
	return 0;
	}
