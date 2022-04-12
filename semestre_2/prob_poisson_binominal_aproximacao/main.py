from math import factorial, e

"""
Aproximação Poisson da Binomial
"""

def combination(n, k):
    """
    Calcula a combinação de n com k
    """
    return (factorial(n) / (factorial(k) * factorial(n - k)))

def binomial(n, x, p):
    """
    Calcula a probabilidade de n acontecer com probabilidade p
    """
    return combination(n, x) * (p ** x) * ((1 - p) ** (n - x))

def poisson(Lambda, x):
    """
    Calcula a probabilidade de x acontecer com probabilidade Lambda
    """
    return ((Lambda ** x) * (e ** (-Lambda))) / factorial(x)

def tests():
    for i in range(1, 7):
        n = 5 * 10 ** i
        p = 2 * 10 ** -i
        Lambda = n * p
        print("\n==========================")
        print("n: {}, p: {}, X=2".format(n, p))
        print("BINOMIAL:", binomial(n, 2, p))
        print("POISSON:", poisson(Lambda, 2))

tests()