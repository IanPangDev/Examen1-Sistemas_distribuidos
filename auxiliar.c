#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcion para llenar el arreglo con valores aleatorios ordenados
void generarArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}