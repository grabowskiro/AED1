/*Crie um programa para manipular vetores. 
O seu programa deve implementar uma função que receba um vetor de inteiros V e retorne um outro vetor de inteiros 
alocado dinamicamente com todos os valores de V que estejam entre o valor mínimo e máximo (que também são passados 
como parâmetro para a função). 

A função deve obedecer ao seguinte protótipo: int* valores_entre(int *v, int n, int min, int max, int *qtd); 

A função recebe: 
	• v: vetor de números inteiros; 
	• n: a quantidade de elementos do vetor v; 
	• min: valor mínimo a ser buscado; 
	• max: valor máximo a ser buscado; 
	
A função deve: 
	• Verificar a quantidade de elementos do vetor que sejam maiores do que min e menores que max; 
	• Caso a quantidade seja maior do que 0 (zero), alocar dinamicamente uma área do exato tamanho necessário 
para armazenar os valores; 
	• Copia os elementos do vetor que sejam maiores do que min e menores que max para a área alocada dinamicamente. 

A função retorna: 
	• O endereço da área alocada dinamicamente, preenchida com os números maiores do que min e menores que max,
ou NULL, caso essa relação de números não tenha sido criada; 
	• A quantidade de números carregados na área alocada dinamicamente, através do parâmetro qtd. 
	
Em seguida, crie a função principal do programa para inicializar um vetor de inteiros, exibir
esses valores na tela e pedir para o usuário digitar o valor mínimo e máximo a ser
buscado. 
Em seguida o programa deverá chamar a função valores_entre e exibir na tela os valores resultantes. 
Lembre-se de exibir uma mensagem de erro caso nenhum valor seja encontrado. 
Não se esqueça de liberar a memória alocada dinamicamente.*/

#include <stdio.h>
#include <stdlib.h>

int* manipulaVet(int *v, int n, int min, int max, int *qtd){
	int elem = 0, i, j=0;
	int *v2;
	for(i=0; i<n; i++){
		if(v[i]>min && v[i]<max) elem++;
	}
	if(elem>0){
		v2 = (int *)malloc(elem * sizeof(int));
		for(i=0; i<n; i++){
			if(v[i]>min && v[i]<max){
				v2[j] = v[i];
				j++;
			}
		}
		*qtd = elem;
		return v2;
	}
	else{
		*qtd = 0;
		return NULL;
	}
}

int main(){
	
	int n;
	
	printf("Digite a quantidade: ");
	scanf("%d", &n);
	
	int vet[n];
	int *vet2;
	int i;
	int qtd;
	
	printf("----------NUMEROS ALEATORIOS ENTRE 0 E 100----------\n");
	
	for(i=0; i<n; i++){
		vet[i] = rand()%100;
		printf("%d ", vet[i]);
	}
	
	printf("\n");
	int max, min;
	
	printf("\nINFORME OS VALORES DE MAXIMO E MINIMO\n");
	printf("Maximo: ");
	scanf("%d", &max);
	printf("Minimo: ");
	scanf("%d", &min);
	
	vet2 = manipulaVet(vet,n,min,max,&qtd);
	
	printf("\nQUANTIDADE DE NUMEROS: %d\n", qtd);
	
	if(qtd == 0) printf("NAO FOI ENCONTRADO NENHUM NUMERO ENTRE OS VALORES DE MAXIMO E MINIMO");
	
	else{
		printf("----------NUMEROS ENTRE OS VALORES DE MAXIMO E MINIMO----------\n");
		for(i=0; i<qtd; i++){
			printf("%d ", vet2[i]);
		}
	}
	
	free(vet2);
	
	return 0;
}
