"""
O polinômio P(x) = (x-2)9 pode
ser escrito em ao menos três formas distintas:
P(x) = (x - 2)9
(1)
= x9 - 18x8 + 144x7 - 672x6 + 2016x5 - 4032x4 + 5376x3 - 4608x2 + 2304x - 512
(2)
= -512 + x(2304 + x(-4608 + x(5376 + x(-4032 + x(2016+
x(-672 + x(144 + x(-18 + x)))))))).

Implemente essas três formas de se calcular o valor de P(x) em funções denomi-
nadas fatorada, expandida e horner. Elas devem ser avaliadas em 161 pontos
regularmente espaçados no intervalo [1,92; 2,08]. Plote os resultados em três figuras
separadas usando a matplotlib.
"""

import numpy as np
import matplotlib.pyplot as plt

def fatorada(x):
    return (x - 2)**9

def expandida(x):
    return x**9 - 18*x**8 + 144*x**7 - 672*x**6 + 2016*x**5 - 4032*x**4 + 5376*x**3 - 4608*x**2 + 2304*x - 512

def horner(x):
    return -512 + x*(2304 + x*(-4608 + x*(5376 + x*(-4032 + x*(2016 + x*(-672 + x*(144 + x*(-18 + x))))))))

def main():
    x = np.linspace(1.92, 2.08, 161)
    plt.plot(x, fatorada(x), label='fatorada')
    plt.plot(x, expandida(x), label='expandida')
    plt.plot(x, horner(x), label='horner')
    plt.legend()
    plt.show()