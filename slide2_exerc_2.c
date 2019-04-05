#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
MATRIZ COM VETOR DE PONTEIROS
	1)Criar e redimencionar uma matriz mxn, onde m e n são fornecidos pelo usuário;
	2)Realizar a leitura dos elementos da matriz;
	3)Fornecer a soma dos elementos da matriz;
	4)Retornar em um vetor(utizando ponteiros) os elementos de uma determinada coluna da matriz;
	5)Imprimir a matriz;
	6)Sair do programa;
	
OBSERVAÇÕES:
1)A matriz deve ser alocada dinamicamente no programa por meio do uso de malloc;
2)O programa deve ser modularizado e utilizar os seguintes protótipos de subalgoritmos:
	a. int **criaMatriz(int **mat, int m, int n);
	b. void leiaMatriz(int **mat, int m, int n);
	c. int somaMatriz(int **mat, int m, int n);
	d. int* colunaMatriz(int **mat, int m, int n, int ncoluna);
	e. void liberaMatriz(int **mat, int ncoluna);
	f. void imprimeMatriz(int **mat, int m, int n);
	g. void imprimeVetor(int *vet, int n);
3)O subalgoritmo int* colunaMatriz(int **mat, int m, int n, int ncoluna) deve criar um novo vetor
(ponteiro para vetor) e retornar o mesmo para o programa principal que será responsável pela impressão
dos valores a partir da chamada de void imprimeVet(int *vet, int n);
 */

void liberaMatriz(int **mat, int ncolunas){
	int i;
	for(i=0; i<ncolunas; i++){
		free(mat[i]);
	}
	free(mat);
}

int **criaMatriz(int **mat, int m, int n){
	mat = (int **)malloc(sizeof(int *)*m);
	if(mat==NULL){
		printf("Sem memoria!");
		return NULL;
	}
	int i;
	for(i=0; i<m; i++){
		mat[i] = (int *)malloc(sizeof(int)*n);
		if(mat[i]==NULL){
			printf("Sem memoria!");
			return NULL;
		}
	}
	
	printf("Matriz criada com sucesso!\n");
	return mat;
}

void leiaMatriz(int **mat, int m, int n){
	int i,j,sel;
	printf("SELECAO DE VALORES:\n1 p/ aleatorios\n2 p/ digitar ");
	scanf("%d", &sel);
	if(sel==1){
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				mat[i][j] = rand()%10;
			}
		}
	}
	if(sel==2){
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				printf("[%d][%d] = ", i,j);
				scanf("%d", &mat[i][j]);
			}
		}
	}
	printf("Valores inseridos com sucesso!\n");
}

int somaMatriz(int **mat, int m, int n){
	int i,j,soma=0;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			soma = soma + mat[i][j];
		}
	}
	return soma;
}

void imprimeMatriz(int **mat, int m, int n){
	int i,j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

int *colunaMatriz(int **mat, int m, int n, int ncoluna){
	int i;
	int *vet;
	for(i=0; i<m; i++){
		vet[i] = mat[i][ncoluna];
	}
	return vet;
}

void imprimeVetor(int *vet, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", vet[i]);
	}
}

int main(){
	
	int opcao;
	int **mat = NULL;
	int m,n,coluna;
	int soma;
	int *vet;
	
	do{
	
		printf("\n\n----------MENU DA MATRIZ----------\n");
		printf("1.Criar a Matriz\n2.Inserir valores para Matriz\n3.Soma da Matriz\n4.Selecionar uma coluna da Matriz\n5.Imprimir Matriz\n6.Sair\n ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("\n------CRIAR MATRIZ-----\n");
				printf("Digite quantas linhas: ");
				scanf("%d", &m);
				printf("Digite quantas colunas: ");
				scanf("%d", &n);
				
				mat = criaMatriz(mat,m,n);
			break;
				
				
			case 2:
				printf("\n------DIGITE MATRIZ-----\n");
				leiaMatriz(mat,m,n);
			break;		
			
			
			case 3:
				printf("\n------SOMA MATRIZ-----\n");
				soma = somaMatriz(mat,m,n);
				printf("Soma = %d\n", soma);
			break;
			
			
			case 4:
				printf("\n------COLUNA MATRIZ-----\n");
				printf("Digite a coluna desejada: ");
				scanf("%d", &coluna);
				vet = colunaMatriz(mat,m,n,coluna);
				imprimeVetor(vet,n);
			break;
			
			
			case 5:
				printf("\n------IMPRIME MATRIZ-----\n");
				imprimeMatriz(mat,m,n);
			break;
			
			
			case 6:
				printf("\nSaindo do programa...\n");
				liberaMatriz(mat,m);
				free(vet);
			break;
			
			
			default:
				printf("\nOpcao Invalida\n");
		}
		
	}while(opcao!=6);
	
	return 0;
}
