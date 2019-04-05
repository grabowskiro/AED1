/* Construa um programa (main) que aloque em tempo de execução (dinamicamente)
uma matriz de ordem m x n (linha por coluna), usando 1+m chamadas a função malloc.
Agora, aproveite este programa para construir uma função que recebendo os
parametros m e n aloque uma matriz de ordem m x n e retorne um ponteiro para esta
matriz alocada. Crie ainda uma função para liberar a área de memória alocada pela
matriz. Finalmente, crie um novo programa (main) que teste/use as duas funções
criadas acima. */

#include <stdio.h>
#include <stdlib.h>

int **alocaMat(int m, int n){
	int **mat;
	
	mat = (int **) malloc (m * sizeof(int *));
	
	int i;
	for(i=0; i<m; i++){
		mat[i] = (int *) malloc (n * sizeof(int));
	}
	return mat;
}

int **freeMat(int m, int n, int **mat){
	int i;
	for(i=0; i<m; i++){
		free(mat[i]);
	}
	free(mat);
	return NULL;
}


int main(){
	
	
	int m,n;
	int **mat;
	
	printf("M = ");
	scanf("%d", &m);
	printf("N = ");
	scanf("%d", &n);
	
	mat = alocaMat(m,n);
	
	int i,j;
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			mat[i][j]= i*j;
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	
	mat = freeMat(m,n,mat);

	return 0;
}
