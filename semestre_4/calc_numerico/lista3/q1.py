"""
    Encontre intervalos que contenham soluções das seguintes equações por in-
    termédio da análise de seus gráficos.
"""

import numpy as np
from matplotlib import pyplot as plt

def f(x):
    return 3*x - np.exp(x) # = 0

def g(x):
    return x + 1 - 2*np.sin(np.pi * x) # = 0

def plot_graph(f, a, b):
    x = np.linspace(a, b, 100)
    y = f(x)
    plt.plot(x, y)
    plt.grid()
    plt.show()

def main():
    plot_graph(f, 0.6, 0.65)
    plot_graph(g, 0.15, 0.25)

if __name__ == '__main__':
    main()