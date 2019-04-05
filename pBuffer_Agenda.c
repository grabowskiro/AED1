#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p{
	char nome[20];
}Pessoa;

void attBuffer(void **pBuffer,int **menu,int **i,int **qp){
    *menu = *pBuffer;
    *i = *menu+1;
    *qp = *i+1;
}

void inserePessoa(void *pBuffer, int *menu, int *i, int *qp){
	Pessoa *p;
	*qp=(*qp)+1;
	
	pBuffer = (void *) realloc(pBuffer, sizeof(*menu) + sizeof(*i) + sizeof(*qp) + ((*qp) * sizeof(Pessoa)));
	if(pBuffer==NULL){
		printf("\nSEM MEMORIA!!!\n");
		exit(1);
	}
	
	p = (Pessoa *) ++qp + ((*qp-1) * sizeof(Pessoa));
	
	setbuf(stdin, NULL);
	printf("\nDigite o nome: ");
	fgets(p->nome,20,stdin);
	printf("Nome adicionado!\n");
	setbuf(stdin, NULL);
  	
  	p = (Pessoa *) ++qp;
}

void buscaPessoa(void *pBuffer, int *menu, int *i, int *qp, Pessoa *p){
	Pessoa *pAux;
	void *pAuxBuffer;
	
	pAuxBuffer = (void *)malloc(sizeof(pBuffer));
	if(pAuxBuffer==NULL){
		printf("\nSEM MEMORIA!!!\n");
		exit(1);
	}
	
	attBuffer(&pAuxBuffer,&menu,&i,&qp);
	p = (Pessoa *)++qp;
	pAux = (Pessoa *)((*qp * sizeof(Pessoa)) + p);
	
	setbuf(stdin,NULL);
	printf("\nDigite um nome: ");
	fgets(pAux->nome,20,stdin);
	setbuf(stdin,NULL);
	
	for(*i=0;*i<*qp;p++){
		if(strcmp(pAux->nome,p->nome)==0){
			printf("Nome encontrado!\n\nINFO\nNome: %s\n", pAux->nome);
		}
		*i++;
	}
	free(pAuxBuffer);
}

void listaAgenda(void *pBuffer, int *menu, int *i, int *qp){ //listaAgenda não funciona, printa nada, provavelmente não está achando o lugar certo na memoria.
	void *pAuxBuffer;
	Pessoa *p;
	
	pAuxBuffer = (void *)malloc(sizeof(pBuffer));
	if(pAuxBuffer==NULL){
		printf("\nSEM MEMORIA!!!\n");
		exit(1);
	}
	
	attBuffer(&pAuxBuffer,&menu,&i,&qp);
	p = (Pessoa *)++qp;
	
	for(*i=0;*i<*qp;++p){
		if(*qp>0) printf("\nINFO\nNome: %s\n", p->nome);
		*i++;
		printf("%d\n", *i);
	}
	free(pAuxBuffer);
}

int main(){
	
	int *menu, *i, *qp; //menu -> escolhe a função, qp -> quantidade de pessoas, i -> auxiliar 
	void *pBuffer;
	Pessoa *p;
	
	pBuffer = (void *)malloc(sizeof(*menu)+sizeof(*i)+sizeof(*qp));
	if(pBuffer==NULL){
		printf("\nSEM MEMORIA!!!\n");
		exit(1);
	}
	
	attBuffer(&pBuffer,&menu,&i,&qp);
	p = (Pessoa *) qp;
	*qp = 0;
	
	
	while(*menu!=5){
		printf("\n==========MENU==========\n1 - Adicionar uma pessoa\n2 - Buscar pessoa\n3 - Listar Agenda\n4 - Remover uma pessoa\n5 - Sair\n");
		scanf("%d", menu);
		setbuf(stdin, NULL);
		switch(*menu){
			case 1:
				inserePessoa(pBuffer,menu,i,qp);
				break;
			case 2:
				buscaPessoa(pBuffer,menu,i,qp,p);
				break;
			case 3:
				listaAgenda(pBuffer,menu,i,qp);
				break;
			case 4:
				//removerPessoa(pBuffer,menu,i,qp);
				break;
			case 5:
				break;
			default:
				printf("Opcao Invalida, tente novamente!\n");
		}
			
	}
	free(pBuffer);
	return 0;
}
