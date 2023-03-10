"""
Elabore uma função em Python que calcula a derivada de um polinômio P
de grau < n. Sua função deve se chamar derivada e ter como argumento de entrada
um arranjo da NumPy contendo os coeficientes de P, armazenados segundo a ordem
decrescente dos graus dos monômios correspondentes. Como resultado, ela deve retornar
um arranjo contendo os coeficientes de P' segundo a mesma ordem descrita anteriormente.
Verifique sua implementação com o polinômio:

P(x) = x^20 - 210x^19 + 20615x^18 - 1256850x^17 + 53327946x^16 .
"""

import numpy as np

# modelo de polinômio: [[coeficiente, grau], [coeficiente, grau], ...]
P = np.array([1, -210, 20615, -1256850, 53327946])
P2 = np.array([[1, 2], [2, 1], [3, 0], [4, -1]])

def ____derivada(p):
    size = len(p)

    return np.array([[p[i, 0] * p[i, 1], p[i, 1] - 1] for i in range(size)])

def derivada(p, n):
    if (p.size > n):
        raise Exception('p > n')

    c = np.arange(n, n - len(p), -1)

    return np.multiply(p, c)

if __name__ == '__main__':
    # derivada_P = derivada(P2)
    # print(derivada_P)
    print(derivada(P, 20))
    # formated_derivada_P = "P'(x) = "
    # for i in range(len(derivada_P)):
    #     if derivada_P[i][0] == 0: continue
    #     formated_derivada_P += "{}x^{} ".format(derivada_P[i][0], derivada_P[i][1]) 
    # print(formated_derivada_P)