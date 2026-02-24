// Bubble Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
        }
    }
}

int* leerArchivo(const char* nombreArchivo, int n, int* tamanoReal) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        printf("Error al abrir el archivo.\n");
        return NULL;
    }

    int* arreglo = (int*) malloc(n * sizeof(int));
    if (!arreglo) {
        fclose(archivo);
        printf("Error al asignar memoria.\n");
        return NULL;
    }

    int num, count = 0;
    while (fscanf(archivo, "%d", &num) == 1 && count < n) {
        arreglo[count++] = num;
    }

    fclose(archivo);
    *tamanoReal = count;
    return arreglo;
}

int main() {
    char nombreArchivo[] = "datos.txt";
    int n;

    printf("Ingrese la cantidad de números a leer del archivo: ");
    scanf("%d", &n);

    int tamanoReal;
    int* arreglo = leerArchivo(nombreArchivo, n, &tamanoReal);
    if (!arreglo) {
        return 1;
    }

    printf("\nDatos leídos del archivo:\n");
    for (int i = 0; i < tamanoReal; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    clock_t start = clock();
    bubble_sort(arreglo, tamanoReal);
    clock_t end = clock();

    double tiempo = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nDatos ordenados con Bubble Sort:\n");
    for (int i = 0; i < tamanoReal; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    printf("\nTiempo de ejecución Bubble Sort: %f segundos\n", tiempo);

    free(arreglo);
    return 0;
}
