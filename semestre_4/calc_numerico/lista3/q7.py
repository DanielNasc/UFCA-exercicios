import numpy as np

# (a) Implemente a função V em Python:

def V(h, r, L):
    r_squared = np.power(r, 2)

    return L * ( \
            (np.pi * r_squared) / 2 \
            - r_squared * np.arcsin((r - h)/r) \
            + (h - r) * np.sqrt(r_squared - np.power((r - h), 2)) \
        )

# (b) r = 1m, L = 7m e h = 1.3m
print(V(1.3, 1, 7))