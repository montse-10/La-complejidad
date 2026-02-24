#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busquedaLineal(int arr[], int n, int k) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            return i;
        }
    }
    return -1;
}

int main() {
    FILE *archivo;
    int *numeros;
    int n, k, pos;

    archivo = fopen("datos.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    printf("Ingrese la cantidad de datos a leer (n): ");
    scanf("%d", &n);

    printf("Ingrese el numero a buscar (k): ");
    scanf("%d", &k);

    numeros = (int*) malloc(n * sizeof(int));
    if (numeros == NULL) {
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

    printf("\n");

    clock_t inicio = clock();
    pos = busquedaLineal(numeros, n, k);
    clock_t fin = clock();

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    if (pos != -1) {
        printf("El numero %d se encontro en la posicion %d.\n", k, pos);
    } else {
        printf("El numero %d NO se encontro.\n", k);
    }

    printf("Tiempo de ejecucion de la busqueda lineal: %f segundos\n", tiempo);

    free(numeros);
    return 0;
}
