#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 1000
#define Y 1000
#define Z 1000

int main() {
    srand(time(NULL));

    // Asignación de memoria dinámica
    int ***matrix = (int ***)malloc(X * sizeof(int **));
    if (matrix == NULL) {
        printf("Error al asignar memoria X\n");
        return 1;
    }

    for (int i = 0; i < X; i++) {
        matrix[i] = (int **)malloc(Y * sizeof(int *));
        if (matrix[i] == NULL) {
            printf("Error al asignar memoria Y en X\n");
            return 1;
        }
        for (int j = 0; j < Y; j++) {
            matrix[i][j] = (int *)malloc(Z * sizeof(int));
            if (matrix[i][j] == NULL) {
                printf("Error al asignar memoria Z en Y\n");
                return 1;
            }
        }
    }

    // Llenado de la matriz con valores aleatorios
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {
                matrix[i][j][k] = rand() % 100;
            }
        }
    }

    // Medir tiempo de recorrido
    clock_t start = clock();

    long long sum = 0;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {
                sum += matrix[i][j][k];
            }
        }
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Tiempo de recorrido: %.3f segundos\n", time_taken);

    // Liberación de memoria
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
