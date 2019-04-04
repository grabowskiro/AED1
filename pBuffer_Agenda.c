#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p{
	char nome[20];
}Pessoa;

void aponta(void **pBuffer,int **menu,int **i,int **qp){
    *menu = *pBuffer;
    *i = *menu+1;
    *qp = *i+1;
}

void inserePessoa(void *pBuffer, int *menu, int *i, int *qp){
	Pessoa *p;
	++*qp;
	pBuffer = (void *)realloc(pBuffer, sizeof(*menu) + sizeof(*i) + sizeof(*qp) + (*qp) * sizeof(Pessoa));
	if(pBuffer==NULL){
		printf("\nSEM MEMORIA!!!\n");
		exit(1);
	}
	
	p = (Pessoa *) ++qp + ((*qp-1) * sizeof(Pessoa));
	
	setbuf(stdin,NULL);
	printf("\nDigite o nome: ");
	fgets(p->nome,20,stdin);
	printf("Nome adicionado!\n");
  	
  	p = (Pessoa *) ++qp;
}

void buscaPessoa(void *pBuffer, int *menu, int *i, int *qp){
	Pessoa *p;
	Pessoa *pAux;
	
	p = (Pessoa *)++qp;
	pAux = (Pessoa *)((*qp * sizeof(Pessoa)) + p);
	
	setbuf(stdin,NULL);
	printf("\nDigite um nome: ");
	fgets(pAux->nome,20,stdin);
	
	for(*i=0;*i<*qp;p++){
		if(strcmp(pAux->nome,p->nome)==0){
			printf("Nome encontrado!\n\nINFO\nNome: %s\n", p->nome);
		}
		*i++;
	}
}

void listaAgenda(void *pBuffer, int *menu, int *i, int *qp){
	Pessoa *p;
	aponta(&pBuffer,&menu,&i,&qp);
	p = (Pessoa *)++qp;
	
	for(*i=0;*i<*qp;p++){
		printf("\nINFO\nNome: %s\n", p->nome);
		*i++;
	}
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
	aponta(&pBuffer,&menu,&i,&qp);
	*qp = 0;
	
	
	while(*menu!=5){
		aponta(&pBuffer,&menu,&i,&qp);
		printf("\n==========MENU==========\n1 - Adicionar uma pessoa\n2 - Buscar pessoa\n3 - Listar Agenda\n4 - Remover uma pessoa\n5 - Sair\n");
		scanf("%d", &(*menu));
		switch(*menu){
			case 1:
				inserePessoa(pBuffer,menu,i,qp);
				break;
			case 2:
				buscaPessoa(pBuffer,menu,i,qp);
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
