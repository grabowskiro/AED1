#include <stdio.h>
#include <stdlib.h>

void imprimeBuffer(void *pBuffer, unsigned int nTotal){

	int i=0;

	for(;i<nTotal;i++){
		printf("    %d\n", *(int*)pBuffer);
		pBuffer= pBuffer+(sizeof (int));
		printf("  %.2f\n", *(float*)pBuffer);
		pBuffer= pBuffer+(sizeof (float));
		printf("%.4lf\n", *(double*)pBuffer);
		pBuffer= pBuffer+(sizeof(double));
		printf("\n");
	}
};



int main(int argc, char **argv)
{

	void *pBuffer;
	void *aux;
	int nTotal,i=0;
	
	printf("Digite a quantidade de trios = ");
	scanf("%d", &nTotal);
	printf("\n");

	pBuffer = (void *) malloc (nTotal*((sizeof (int))+(sizeof (float))+(sizeof (double))));
	aux=pBuffer;

	for(;i<nTotal;i++){
		*(int*)aux = rand() %10;
		aux = aux+(sizeof (int));
		*(float*)aux = rand() %1000;
		aux = aux+(sizeof(float));
		*(double*)aux = rand() %100000;
		aux = aux+(sizeof(double));
	}

	imprimeBuffer(pBuffer, nTotal);
	free(pBuffer);

	return 0;
}
