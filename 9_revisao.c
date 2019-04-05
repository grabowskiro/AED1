/*	Crie um programa que implemente o jogo “Bingo de Prog II”. Nesse jogo, o jogador deve selecionar a quantidade 
de números que ele gostaria de apostar (entre 1 e 20), e em seguida, informar os números escolhidos 
(valores entre 0 e 100). 
	Após receber a aposta, o computador sorteia 20 números (entre 0 e 100) e compara os números sorteados com os 
números apostados, informando ao apostador a quantidade de acertos e os números que ele acertou. 

	O seu programa deverá implementar as funções ler_aposta, sorteia_valores e compara_aposta. 
	
	A função ler_aposta deve receber como parâmetro a quantidade de números que serão apostados e um vetor
previamente alocado dinamicamente para armazenar a quantidade exata de números apostados.  A função deve pedir 
para o usuário digitar os números apostados e armazena-los no vetor, garantindo que somente números dentro do 
intervalo de 0 a 100 sejam digitados. 
	A função deve seguir o seguinte protótipo: 
		void ler_aposta(int *aposta, int n); 
		
	A função sorteia_valores deve receber como parâmetro a quantidade de números que serão sorteados e um vetor 
previamente alocado dinamicamente para armazenar a quantidade exata de números sorteados. A função deve sortear 
aleatoriamente os números (entre 0 e 100) e armazena-los no vetor. 
	A função deve seguir o seguinte protótipo: 
		void sorteia_valores(int *sorteio, int n); 
		
	A função compara_aposta deve receber como parâmetro o vetor com os números apostados (aposta), o vetor com os 
números sorteados (sorteio), juntamente com os seus respectivos tamanhos (na e ns) e um ponteiro para uma variável 
inteira (qtdacertos), onde deve ser armazenada a quantidade de acertos. A função deve retornar o ponteiro para um 
vetor alocado dinamicamente contendo os números que o apostador acertou. 
	A função deve seguir o seguinte protótipo: 
		int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns); 
		
	Em seguida, crie a função principal do programa utilizado as funções criadas anteriormente para implementar o 
jogo “Bingo de Prog II”. Lembre-se que os vetores aposta, sorteio e acertos devem ser alocados dinamicamente e a 
memória alocada deve liberada quando ela não for mais ser utilizada. Para sortear números aleatórios utilize a função
rand da biblioteca stdlib.h. 
	A função rand retorna um número aleatório em um determinado intervalo. 
		Exemplo: x = rand() % 10; x vai receber um valor entre 0 e 10 
	Para garantir que novos números aleatórios sejam sorteados em cada execução do programa é necessário executar a 
função srand antes de sortear os números.

srand(time(NULL)) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int *aposta, int n){
	int i = 0;
	int aux;
	printf("\n----------DIGITE NUMEROS ENTRE 0 E 100----------\n");
	while(i<n){
		printf("Numero %d = ", i+1);
		scanf("%d", &aux);
		if(aux>=0 && aux<=100){
			aposta[i]=aux;
			i++;
		}
		else{
			printf("NUMERO INVALIDO!\n\nDigite Novamente: \n");
		}
	}
}

void sorteia_valores(int *sorteio, int n){
	int i;
	for(i=0; i<n; i++){
		sorteio[i] = rand()%100;
	}
}

int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns){
	int *vet;
	int i, j;
	int n=0;
	for(i=0; i<na; i++){
		for(j=0; j<ns; j++){
			if(aposta[i]==sorteio[j]){
				n++;
			}
		}
	}
	vet = (int *)malloc(sizeof(int) * n);
	n=0;
	for(i=0; i<na; i++){
		for(j=0; j<ns; j++){
			if(aposta[i]==sorteio[j]){
				vet[n]=aposta[i];
				n++;
			}
		}
	}
	*qtdacertos = n;
	return vet;
}

void printVet(int *vet, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", vet[i]);
	}
}

int main(){
	
	srand(time(NULL));
	
	int n_aposta, *vet_aposta;
	int n_sorteio, *vet_sorteio;
	int n_acertos, *vet_acertos;
	
	do{
		printf("DIGITE A QUANTIDADE DE NUMEROS PARA APOSTA DE 1 A 20: ");
		scanf("%d", &n_aposta);
		if(n_aposta>0 && n_aposta<=20){
			vet_aposta = (int *)malloc(sizeof(int) * n_aposta);
			ler_aposta(vet_aposta, n_aposta);
		}
		else printf("VALOR DE APOSTAS INVALIDO!\n\n");
	}while(n_aposta<1 || n_aposta>20);
	
	printf("\nDIGITE A QUANTIDADE DE NUMEROS PARA SORTEIO: ");
	scanf("%d", &n_sorteio);
	
	vet_sorteio = (int *)malloc(sizeof(int) * n_sorteio);
	sorteia_valores(vet_sorteio,n_sorteio);
	
	printf("\nAPOSTA\n");
	printVet(vet_aposta, n_aposta);
	printf("\n\nSORTEIO\n");
	printVet(vet_sorteio, n_sorteio);
	printf("\n\nNUMEROS ACERTADOS\n");
	
	vet_acertos = compara_aposta(vet_aposta, vet_sorteio, &n_acertos, n_aposta, n_sorteio);
	printVet(vet_acertos, n_acertos);
	printf("\nQUANTIDADE DE NUMEROS: %d\n", n_acertos);
	
	free(vet_aposta);
	free(vet_sorteio);
	free(vet_acertos);
	
	return 0;
}
