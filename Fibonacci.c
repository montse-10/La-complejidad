// Función recursiva de Fibonacci

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Ingrese el valor de n para Fibonacci: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("n debe ser un número no negativo.\n");
        return 1;
    }

    printf("\nCalculando la serie de Fibonacci hasta %d...\n", n);

    clock_t inicio = clock();

    for (int i = 0; i <= n; i++) {
        printf("%llu ", fibonacci(i));
    }

    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("\n\nTiempo de ejecucion: %.6f segundos\n", tiempo);

    return 0;
}
