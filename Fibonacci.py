import time


def fibonacci(n):
    if n <= 0:
        return 0
    if n == 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)


def main():
    try:
        n = int(input("Ingrese el valor de n para Fibonacci: "))

        if n < 0:
            print("n debe ser un número no negativo.")
            return

        print(f"\nCalculando la serie de Fibonacci hasta {n}...")

        inicio = time.time()

        for i in range(n + 1):
            print(fibonacci(i), end=" ")

        fin = time.time()
        tiempo = fin - inicio

        print(f"\n\nTiempo de ejecución: {tiempo:.6f} segundos")

    except ValueError:
        print("Por favor, ingrese un número entero válido.")


if __name__ == "__main__":
    main()
