import time


def merge_sort(arr):
    _merge_sort_recursive(arr, 0, len(arr) - 1)


def _merge_sort_recursive(arr, left_idx, right_idx):

    if left_idx < right_idx:
        mid_idx = (left_idx + right_idx) // 2
        _merge_sort_recursive(arr, left_idx, mid_idx)
        _merge_sort_recursive(arr, mid_idx + 1, right_idx)
        _merge(arr, left_idx, mid_idx, right_idx)


def _merge(arr, left_idx, mid_idx, right_idx):
    left_half = arr[left_idx: mid_idx + 1]
    right_half = arr[mid_idx + 1: right_idx + 1]

    left_half.append(float('inf'))
    right_half.append(float('inf'))

    i = j = 0

    for k in range(left_idx, right_idx + 1):
        if left_half[i] <= right_half[j]:
            arr[k] = left_half[i]
            i += 1
        else:
            arr[k] = right_half[j]
            j += 1


def binary_search(arr, k):
    left, right = 0, len(arr) - 1

    while left <= right:

        mid = (left + right) // 2

        if arr[mid] == k:
            return mid
        elif arr[mid] < k:
            left = mid + 1
        else:
            right = mid - 1
    return -1


def main():
    try:

        with open('datos.txt', 'r') as archivo:
            todos_los_numeros = [int(num) for num in archivo.read().split()]

        n = int(input("Ingrese la cantidad de datos a leer (n): "))
        k = int(input("Ingrese el numero a buscar (k): "))

        if n > len(todos_los_numeros):
            print("No hay suficientes datos en el archivo.")
            return

        numeros = todos_los_numeros[:n]

        numeros_a_ordenar = list(numeros)
        inicio_orden = time.perf_counter()
        merge_sort(numeros_a_ordenar)
        fin_orden = time.perf_counter()
        tiempo_orden = fin_orden - inicio_orden

        inicio_busq = time.perf_counter()
        pos = binary_search(numeros_a_ordenar, k)
        fin_busq = time.perf_counter()
        tiempo_busq = fin_busq - inicio_busq

        if pos != -1:
            print(f"\nEl numero {k} se encontro en la posicion {pos}.")
        else:
            print(f"\nEl numero {k} NO se encontro.")

        print(f"\nTiempo de ordenamiento (Merge Sort): {tiempo_orden:.6f} segundos")
        print(f"Tiempo de busqueda binaria: {tiempo_busq:.6f} segundos")

    except FileNotFoundError:
        print("Error: El archivo 'datos.txt' no se encontró.")
    except ValueError:
        print("Error: Por favor, ingrese números enteros válidos.")
    except Exception as e:
        print(f"Ocurrió un error inesperado: {e}")


if __name__ == "__main__":
    main()
