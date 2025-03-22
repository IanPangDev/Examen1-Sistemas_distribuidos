#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void get_walltime(double* wcTime ) {
    struct timeval tp;
    gettimeofday(&tp ,NULL);
    *wcTime=(tp.tv_sec + tp.tv_usec / 1000000.0);
}

void imprimirMatriz2D(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]){
    int i, j, k, n=10000;
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
            matrizB[i][j] = rand() % 6;
        }
    }
    
    // Inicializar C con ceros
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrizC[i][j] = 0;   // Inicialización correcta
        }
    }

    get_walltime(&S1);

    for (j=0;j<n;++j){
        for (i=0;i<n;++i){
            for (k=0;k<n;++k){
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    get_walltime(&E1);

    printf("Tiempo método ijk: %f s\n", (E1-S1));
    
    // Llamar a la función para imprimir las matrices
    // printf("Matriz A:\n");
    // imprimirMatriz2D(matrizA, n);
    
    // printf("Matriz B:\n");
    // imprimirMatriz2D(matrizB, n);
    
    // printf("Matriz C:\n");
    // imprimirMatriz2D(matrizC, n);
    
    return 0;
}