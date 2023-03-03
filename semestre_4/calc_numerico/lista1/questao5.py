"""
Podemos definir a sequência de Fibonacci usando recursividade. Com efeito,
definimos F0 = 0 e F1 = 1, os quais chamamos de casos base. Agora, estabelecemos a

Um algoritmo matricial bastante elegante que nos permite usar os arranjos da NumPy
para calcular os termos dessa sequência se baseia na seguinte equação:

    [ Fn Fn-1 ] = [ [1 1] [1 0] ][ Fn-1 Fn-2]

Utilize a equação acima para desenvolver e implementar em Python o algoritmo ma-
tricial em uma função denominada fibmat. Esta função deve retornar o valor de Fn .
"""

import numpy as np

# https://mathworld.wolfram.com/FibonacciQ-Matrix.html
def fibmat(n):
    if n == 0: return 0
    elif n == 1: return 1

    fib_array = np.array([[1, 1], [1, 0]])
    fib_array = np.linalg.matrix_power(fib_array, n - 1)

    return fib_array[0, 0]

# usando um array para guardar os valores de fibonacci
# assim, não precisamos calcular novamente os valores
# e a função fica mais rápida
fib_values = [0, 1]

def fibmat2(n):
    if n <= 0: return 0
    elif n == 1: return 1

    first_values = np.array([[1, 1], [1, 0]])
    
    fib_matrix = np.dot(first_values, np.array([fib_values[n - 1], fib_values[n - 2]]))

    if (len(fib_values) - 1) < n:
        fib_values.append(fib_matrix[0])

    print(fib_matrix)
    return fib_matrix[0]

# usando recursividade
# a função fica mais lenta
def fibmat2_recursive(n):
    if n <= 0: return 0
    elif n == 1: return 1

    first_values = np.array([[1, 1], [1, 0]])
    
    fib_matrix = np.dot(first_values, np.array([fibmat2_recursive(n - 1), fibmat2_recursive(n - 2)]))

    return fib_matrix[0]


if __name__ == '__main__':
    for i in range(66):
        print("fibmat({}) = {}".format(i, fibmat2(i)))