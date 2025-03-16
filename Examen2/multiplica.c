#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void get_walltime(double* wcTime ) {
    struct timeval tp;
    gettimeofday(&tp ,NULL);
    *wcTime=(tp.tv_sec + tp.tv_usec / 1000000.0);
}

int main(int argc, char* argv[]){
    int i, j, k, n=5000;
    int **matrizA, **matrizB, **matrizC;
    double S1, E1;
    matrizA = (int **)malloc(n*sizeof(int*));
    matrizB = (int **)malloc(n*sizeof(int*));
    matrizC = (int **)malloc(n*sizeof(int*));
    for (i=0;i<n;i++)
        *(matrizA+i) = (int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
        *(matrizB+i) = (int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
        *(matrizC+i) = (int*)malloc(n*sizeof(int));

    for (i=0;i<n;++i){
        for (j=0; j<n;++j){
            matrizA[i][j] = rand() % 6;
        }
    }
    
    for (i=0;i<n;++i){
        for (j=0; j<n;++j){
            matrizB[i][j] = rand() % 6;
        }
    }

    get_walltime(&S1);

    for (j=0;j<n;++j){
        for (k=0;k<n;++k){
            for (i=0;i<n;++i){
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    get_walltime(&E1);

    printf("Tiempo método ijk: %f s\n", (E1-S1));
    return 0;
}