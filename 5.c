/* Criar um tipo abstrato de dados que represente uma pessoa, contendo nome, data de
nascimento e CPF. Crie uma variável que é um ponteiro para este TAD (no programa
principal). Depois crie uma função que receba este ponteiro e preencha os dados da
estrutura e também uma uma função que receba este ponteiro e imprima os dados da
estrutura. Finalmente, faça a chamada a esta função na função principal. */

#include <stdio.h>
#include <stdlib.h>

struct d{
	int dia;
	int mes;
	int ano;
};

struct c{
	int cpf1;
	int cpf2;
	int cpf3;
	int cpf4;
};

struct pessoa{
	char *nome;
	struct d data;
	struct c cpf; 
};

void preenchePessoa(struct pessoa** p){
	*p = (struct pessoa*)malloc(sizeof(struct pessoa));
	(*p)->nome = malloc(100);
	printf("Nome : ");
	scanf("%s", (*p)->nome);
	getchar();
	printf("Data de nascimento: ");
	scanf("%d/%d/%d", &(*p)->data.dia, &(*p)->data.mes, &(*p)->data.ano);
	printf("Digite seu CPF: ");
	scanf("%d.%d.%d-%d", &(*p)->cpf.cpf1, &(*p)->cpf.cpf2, &(*p)->cpf.cpf3, &(*p)->cpf.cpf4);
}

void imprimePessoa(struct pessoa* p){
	printf("%s\n", p->nome);
	printf("%d/%d/%d \n", p->data.dia, p->data.mes, p->data.ano);
	printf("%d.%d.%d-%d", p->cpf.cpf1, p->cpf.cpf2, p->cpf.cpf3, p->cpf.cpf4);
}

int main(){
	
	struct pessoa* p;
	
	preenchePessoa(&p);
	imprimePessoa(p);

	return 0;
}
