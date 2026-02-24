import time


def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


def leer_archivo(nombre_archivo, n):
    try:
        with open(nombre_archivo, 'r') as archivo:
            todos_los_numeros = [int(num) for num in archivo.read().split()]
            return todos_los_numeros[:n]
    except FileNotFoundError:
        print(f"Error: El archivo '{nombre_archivo}' no se encontró.")
        return None
    except ValueError:
        print("Error: El archivo contiene datos que no son números enteros.")
        return None


def main():
    nombre_archivo = "datos.txt"

    try:
        n_str = input("Ingrese la cantidad de números a leer del archivo: ")
        n = int(n_str)
    except ValueError:
        print("Error: Ingrese un número entero válido.")
        return

    arreglo = leer_archivo(nombre_archivo, n)

    if arreglo is None:
        return

    print("\nDatos leídos del archivo:")
    print(*arreglo)

    start_time = time.perf_counter()
    bubble_sort(arreglo)
    end_time = time.perf_counter()

    tiempo = end_time - start_time

    print("\nDatos ordenados con Bubble Sort:")
    print(*arreglo)

    print(f"\nTiempo de ejecución Bubble Sort: {tiempo:.6f} segundos")


if __name__ == "__main__":
    main()
