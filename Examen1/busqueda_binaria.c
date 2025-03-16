#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "auxiliar.c"

// FunciÃ³n de busqueda binaria
int busquedaBinaria(int arr[], int izquierda, int derecha, int objetivo) {
    
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == objetivo) {
            return medio;
        }

        if (arr[medio] > objetivo)
            derecha = medio - 1;
        else
            izquierda = medio + 1;
    }

    return -1;
}

int main() {
    srand(time(NULL));

    int n = 100000000;

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    generarArreglo(arr, n);

    int objetivo = arr[rand() % n];

    clock_t inicio = clock(); // Inicio del temporizador
    int resultado = busquedaBinaria(arr, 0, n - 1, objetivo);
    clock_t fin = clock(); // Fin del temporizador
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de búsqueda: %f segundos\n", tiempo);

    if (resultado != -1)
        printf("Elemento encontrado en la posicion %d\n", resultado);
    else
        printf("Elemento no encontrado\n");

    return 0;
}
