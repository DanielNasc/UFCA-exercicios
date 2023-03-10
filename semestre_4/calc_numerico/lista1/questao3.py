"""
(Hill, 2016). O método de Gauss para o cálculo da área de um polígono sim-
ples funciona do seguinte modo. Considere um polígono simples com n vértices (x1 , y1 ),
(x2 , y2 ), . . . , (xN , yN ), N ≥ 3, ordenados no sentido anti-horário. Armazene as coordena-
das desses pontos em um arranjo (N + 1) ^ 2, repetindo na última linha as coordenadas do
primeiro vértice. Agora, (a) multiplique cada coordenada x das primeiras N linhas pela
coordenada y da linha imediatamente abaixo e tome a soma S1 = x1 y2 + x2 y3 + · · · + xN y1 .
Depois, (b) multiplique cada coordenada y das N primeiras linhas pela coordenada x da
linha imediatamente abaixo e tome a soma S2 = y1 x2 + y2 x3 + · · · + yN x1 . Então, a área
do polígono será 21 |S1 - S2 |.

Implemente esse algoritmo como uma função em Python que recebe dois arranjos x e y
da NumPy como entrada e retorna a área do poligono.


Verifique sua implementação no polígono de coordenadas:
# Abcissas
x = np . a r r a y ( [ 0 . 5 , 8 . 0 , 1 9 . 0 , 2 6 . 0 , 1 5 . 0 , 4 . 0 ] )
# Ordenadas
y = np . a r r a y ( [ 0 . 5 , 4 . 0 , 1 1 . 0 , 2 5 . 0 , 2 7 . 0 , 9 . 0 ] )
"""

import numpy as np

x = np.array([0.5, 8.0, 19.0, 26.0, 15.0, 4.0])
y = np.array([0.5, 4.0, 11.0, 25.0, 27.0, 9.0])

a = np.array([0, 2])

def area_gauss(x, y):
    N = len(x)
    S1 = 0
    S2 = 0
    
    if (N < 3 or N != len(y)): return None

    xx = np.concatenate((x, [x[0]]))
    xy = np.concatenate((y, [y[0]]))

    S1 = np.dot(x, xy[1:])
    S2 = np.dot(xx[1:], y)

    return np.abs(S1 - S2) * .5

if __name__ == '__main__':
    print(area_gauss(x, y))