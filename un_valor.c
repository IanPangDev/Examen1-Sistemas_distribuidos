#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int a[1] = {rand() % 100};

    // Medir tiempo de recorrido
    clock_t start = clock();
    int sum = a[0] + 0;
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Tiempo de recorrido: %.3f segundos\n", time_taken);

    return 0;
}