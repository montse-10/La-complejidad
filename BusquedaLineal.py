import time


def busqueda_lineal(arr, k):
    for indice, valor in enumerate(arr):
        if valor == k:
            return indice
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

        print("\nIniciando búsqueda...")

        inicio = time.perf_counter()
        pos = busqueda_lineal(numeros, k)
        fin = time.perf_counter()

        tiempo = fin - inicio

        if pos != -1:

            print(f"El numero {k} se encontro en la posicion {pos}.")
        else:
            print(f"El numero {k} NO se encontro.")

        print(f"Tiempo de ejecucion de la busqueda lineal: {tiempo:.6f} segundos")

    except FileNotFoundError:
        print("Error: El archivo 'datos.txt' no se encontró en el directorio.")
    except ValueError:
        print("Error: Por favor, ingrese un número entero válido.")
    except Exception as e:
        print(f"Ocurrió un error inesperado: {e}")


if __name__ == "__main__":
    main()
