/* Faça uma função que receba um valor n e crie dinamicamente um vetor de n
elementos e retorne um ponteiro. Crie uma função que receba um ponteiro para um
vetor e um valor n e imprima os n elementos desse vetor. Construa também uma
função que receba um ponteiro para um vetor e libere esta área de memória. Ao final,
crie uma função principal que leia um valor n e chame a função criada acima. Depois, a
função principal deve ler os n elementos desse vetor. Então, a função principal deve
chamar a função de impressão dos n elementos do vetor criado e, finalmente, liberar a
memória alocada através da função criada para liberação. */

#include <stdio.h>
#include <stdlib.h>

int* vetDinamic(int tam){
	int *p;
	p = (int *)malloc(sizeof(int)*tam);
	return p;
}

void printVet(int tam, int *p){
	int i;
	for(i=0; i<tam; i++){
		printf("%d\n", p[i]);
	}
}

void freeVet(int *p){
	free(p);
}

void funPrinc(int n){
	int *p;
	
	printf("Valor= ");
	scanf("%d", &n);
	
	p = vetDinamic(n);
	
	int i;
	for(i=0; i<n; i++){
		p[i] = i+1;
	}
	
	printVet(n,p);
	freeVet(p);
}

int main(){
	
	int n;
	
	funPrinc(n);
	
	return 0;
}
