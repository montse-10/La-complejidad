// Merge Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void merge(int *A, int ini, int mit, int fin) {
    int tizq = mit - ini + 1;
    int tder = fin - mit;
    int *I = (int*) malloc((tizq + 1) * sizeof(int));
    int *D = (int*) malloc((tder + 1) * sizeof(int));

    for (int i = 0; i < tizq; i++) I[i] = A[ini + i];
    for (int j = 0; j < tder; j++) D[j] = A[mit + 1 + j];

    I[tizq] = INT_MAX;
    D[tder] = INT_MAX;

    int i = 0, j = 0;
    for (int k = ini; k <= fin; k++) {
        if (I[i] <= D[j]) {
            A[k] = I[i++];
        } else {
            A[k] = D[j++];
        }
    }

    free(I);
    free(D);
}

void merge_sort(int *A, int ini, int fin) {
    if (ini < fin) {
        int mit = (ini + fin) / 2;
        merge_sort(A, ini, mit);
        merge_sort(A, mit + 1, fin);
        merge(A, ini, mit, fin);
    }
}

int* leerArchivo(const char* nombreArchivo, int tamano, int* tamanoReal) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        printf("Error al abrir %s.\n", nombreArchivo);
        return NULL;
    }

    int* arreglo = (int*) malloc(tamano * sizeof(int));
    if (!arreglo) {
        fclose(archivo);
        printf("Error al asignar memoria.\n");
        return NULL;
    }

    int num, count = 0;
    while (fscanf(archivo, "%d", &num) == 1 && count < tamano) {
        arreglo[count++] = num;
    }

    fclose(archivo);
    *tamanoReal = count;
    return arreglo;
}

int main() {
    int n, tamanoReal;
    char nombreArchivo[] = "datos.txt";

    printf("Ingrese la cantidad de numeros a leer: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("El valor de n debe ser positivo.\n");
        return 1;
    }

    int* arreglo = leerArchivo(nombreArchivo, n, &tamanoReal);
    if (!arreglo) return 1;

    printf("\nDatos antes de ordenar:\n");
    for (int i = 0; i < tamanoReal; i++) printf("%d ", arreglo[i]);
    printf("\n");

    clock_t inicio = clock();
    merge_sort(arreglo, 0, tamanoReal - 1);
    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("\nDatos ordenados:\n");
    for (int i = 0; i < tamanoReal; i++) printf("%d ", arreglo[i]);
    printf("\n");

    printf("\nTiempo de ejecucion Merge Sort: %f segundos\n", tiempo);

    free(arreglo);
    return 0;
}
