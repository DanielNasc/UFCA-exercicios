"""
    Verifique se o método da bisseção pode ser empregado para calcular o zero
    da função f (x) = ln x + x^2 - 3 no intervalo [1, 2].
"""

import numpy as np

def bissecao(f, a, b, N):
    assert not a >= b, "Intervalo inválido"
    
    fa = f(a)
    fb = f(b)

    assert np.sign(fa) * np.sign(fb) < 0, "Não há raiz no intervalo"

    for i in range(N):
        p = (a + b)/2
        fp = f(p)

        if fp == 0:
            print("Raiz: {0}".format(p))
            return p, i
        
        if np.sign(fa) * np.sign(fp) < 0:
            b = p
        else:
            a = p
        
    return p, i

def f(x):
    return np.log(x) + x**2 - 3

def main():
    a = 1
    b = 2
    N = 100000000

    p, i = bissecao(f, a, b, N)

    print("Raiz: {0}".format(p))
    print("Iterações: {0}".format(i))

if __name__ == "__main__":
    main()