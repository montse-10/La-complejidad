#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void merge(int *A, int ini, int mit, int fin) {
    int izq = mit - ini + 1;
    int der = fin - mit;

    int *I = (int*) malloc((izq + 1) * sizeof(int));
    int *D = (int*) malloc((der + 1) * sizeof(int));

    for (int i = 0; i < izq; i++) I[i] = A[ini + i];
    for (int j = 0; j < der; j++) D[j] = A[mit + 1 + j];

    I[izq] = INT_MAX;
    D[der] = INT_MAX;

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

int busquedaBinaria(int arr[], int n, int k) {
    int inicio = 0, fin = n - 1;

    while (inicio <= fin) {
        int mid = (inicio + fin) / 2;

        if (arr[mid] == k) {
            return mid;
        } else if (arr[mid] < k) {
            inicio = mid + 1;
        } else {
            fin = mid - 1;
        }
    }
    return -1;
}

int main() {
    FILE *archivo;
    int *numeros;
    int n, k, pos;

    archivo = fopen("datos.txt", "r");
    if (!archivo) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    printf("Ingrese la cantidad de datos a leer (n): ");
    scanf("%d", &n);

    printf("Ingrese el numero a buscar (k): ");
    scanf("%d", &k);

    numeros = (int*) malloc(n * sizeof(int));
    if (!numeros) {
        printf("Error al reservar memoria.\n");
        fclose(archivo);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(archivo, "%d", &numeros[i]) != 1) {
            printf("No hay suficientes datos en el archivo.\n");
            free(numeros);
            fclose(archivo);
            return 1;
        }
    }
    fclose(archivo);

    clock_t inicio_orden = clock();
    merge_sort(numeros, 0, n - 1);
    clock_t fin_orden = clock();
    double tiempo_orden = (double)(fin_orden - inicio_orden) / CLOCKS_PER_SEC;

    clock_t inicio_busq = clock();
    pos = busquedaBinaria(numeros, n, k);
    clock_t fin_busq = clock();
    double tiempo_busq = (double)(fin_busq - inicio_busq) / CLOCKS_PER_SEC;

    if (pos != -1) {
        printf("El numero %d se encontro en la posicion %d.\n", k, pos);
    } else {
        printf("El numero %d NO se encontro.\n", k);
    }

    printf("\nTiempo de ordenamiento (Merge Sort): %f segundos\n", tiempo_orden);
    printf("Tiempo de busqueda binaria: %f segundos\n", tiempo_busq);

    free(numeros);
    return 0;
}
