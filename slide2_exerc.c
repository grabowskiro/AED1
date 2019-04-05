#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Faça um programa que armazene a informação de várias pessoas.
O programa só deve sair quando o usuário disser que não deseja mais entrar com os dados de outra pessoa.
 Antes de sair o programa deve apresentar, de forma organizada, os dados de todas as pessoas.
 */

typedef struct{
	char nome[30];
	int idade;
	int altura;
}Pessoa;

struct no{
	Pessoa p;
	struct no* prox;
};

void insert(Pessoa *p, struct no** l){
	if(*l == NULL){
		*l = (struct no*)malloc(sizeof(struct no));
		strcpy((*l)->p.nome, p->nome);
		(*l)->p.idade = p->idade;
		(*l)->p.altura = p->altura;
		(*l)->prox = NULL;
	}
	else{
		struct no* aux;
		for(aux = *l; aux->prox != NULL; aux=aux->prox);
		aux->prox = (struct no*)malloc(sizeof(struct no));
		strcpy(aux->prox->p.nome, p->nome);
		aux->prox->p.idade = p->idade;
		aux->prox->p.altura = p->altura;
		aux->prox->prox = NULL;
	}
}

void lista( struct no* l ){
	struct no* aux;
	for(aux = l; aux != NULL; aux = aux->prox){
		printf(" NOME   : %s\n", aux->p.nome);
		printf(" IDADE  : %d Anos\n", aux->p.idade);
		printf(" ALTURA : %dcm\n\n", aux->p.altura);
	}
	printf("\n");
}

int main(){
	
	int aux;
	Pessoa *p;
	struct no *l = NULL;
	
	do{
		p=(Pessoa *)malloc(sizeof(Pessoa));
		printf("\n----------INSIRA OS DADOS----------\n");
		printf("Nome: ");
		scanf("%s", p->nome);
		
		printf("Idade: ");
		scanf("%d", &p->idade);
		
		printf("Altura: ");
		scanf("%d", &p->altura);
		
		insert(p,&l);

		free(p);
	
		printf("Deseja entrar com mais dados? 1 p/ Sim - 0 p/ Nao");
		scanf("%d", &aux);
	
	}while(aux!=0);
	
	printf("\n----------LISTA----------\n");
	lista(l);
	free(l);
	
	return 0;
}
