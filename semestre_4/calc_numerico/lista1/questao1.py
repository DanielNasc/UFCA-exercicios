import math

def calc_e():
    # 1.0 + 1.0e-20 == 1.0

    eps = 1

    while 1 + eps != 1.0:
        eps /= 2

    # formula to calculate e
    # math.pow(1 + eps, 1 / eps) == math.e
    eps *= 2

    print('\n')
    print('eps =', eps)
    print("\n")

    
    return math.pow(1 + eps, 1 / eps)

if __name__ == '__main__':
    print(calc_e())