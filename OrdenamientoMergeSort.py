import time


def _merge(arr, left, mid, right):
    left_half = arr[left: mid + 1]
    right_half = arr[mid + 1: right + 1]

    left_half.append(float('inf'))
    right_half.append(float('inf'))

    i = j = 0
    for k in range(left, right + 1):
        if left_half[i] <= right_half[j]:
            arr[k] = left_half[i]
            i += 1
        else:
            arr[k] = right_half[j]
            j += 1


def _merge_sort_recursive(arr, left, right):
    if left < right:
        mid = (left + right) // 2
        _merge_sort_recursive(arr, left, mid)
        _merge_sort_recursive(arr, mid + 1, right)
        _merge(arr, left, mid, right)


def merge_sort(arr):
    if len(arr) > 1:
        _merge_sort_recursive(arr, 0, len(arr) - 1)


def leer_archivo(nombre_archivo, n):
    try:
        with open(nombre_archivo, 'r') as archivo:
            todos_los_numeros = [int(num) for num in archivo.read().split()]
            return todos_los_numeros[:n]
    except FileNotFoundError:
        print(f"Error al abrir {nombre_archivo}.")
        return None
    except ValueError:
        print("Error: El archivo contiene datos no numéricos.")
        return None


def main():
    nombre_archivo = "datos.txt"

    try:
        n_str = input("Ingrese la cantidad de numeros a leer: ")
        n = int(n_str)
    except ValueError:
        print("Error: Ingrese un número entero válido.")
        return

    if n <= 0:
        print("El valor de n debe ser positivo.")
        return

    arreglo = leer_archivo(nombre_archivo, n)

    if arreglo is None:
        return

    print("\nDatos antes de ordenar:")
    print(*arreglo)

    inicio = time.perf_counter()
    merge_sort(arreglo)
    fin = time.perf_counter()

    tiempo = fin - inicio

    print("\nDatos ordenados:")
    print(*arreglo)

    print(f"\nTiempo de ejecucion Merge Sort: {tiempo:.6f} segundos")


if __name__ == "__main__":
    main()
