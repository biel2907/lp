#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 3

double ** aloca_matriz(int m, int n) {
	int i;
	double **res = (double **) malloc (m*sizeof(double *));
	for (i=0; i<n; i++)
		res[i] = (double *) malloc (TAM*sizeof(double));
	return res;
}

void remove_matriz(double **mat) {
	int i;
	for (i=0; i<TAM; i++)
		free(mat[i]);
	free(mat);
}

double ** mult_matrizes (double **m1, double **m2) {
	int i, j, k;
	double **res = aloca_matriz(TAM, TAM);
	
	for (i=0; i<TAM; i++)
		for (j=0; j<TAM; j++)
			for (k=0; k<TAM; k++)
				res[i][j] = res[i][j] + m1[i][k]*m2[k][j];
	return res;
}

double ** mult_matrizes2 (double **m1, double *m2) {
	int i, j, k;
	double **res = aloca_matriz(TAM, TAM);
	
	printf("Antes!\n");
	printf("%g\n", m2[1]);
	printf("Depois!\n");

	return res;
}

double ** aleatorio () {
	int i, j;
	double **res = aloca_matriz(TAM, TAM);
	
	for (i=0; i<TAM; i++) {
		for (j=0; j<TAM; j++) {
			res[i][j] = rand() % 100;
		}
	}
	return res;
}

main(void)
{
	time_t inicio, fim;
	int i;
	double **A, **B, **C, D[TAM][TAM] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
	
	A = aleatorio();
	B = aleatorio();
	
	inicio=time(NULL);
	C = mult_matrizes2(A, D);
	fim=time(NULL);

	// Formato retornado pela asctime: DDD MMM dd hh:mm:ss YYYY
	//printf("The current time is %s\n",asctime(localtime(&inicio)));	
	printf("\nDiff tempo = %f\n", (double)(fim - inicio));
	printf("\nDiff tempo = %f\n", difftime(fim, inicio));
	
	remove_matriz(A);
	remove_matriz(B);
	remove_matriz(C);
}

