import math

def calc_e():
    # 1.0 + 1.0e-20 == 1.0

    eps = 1
    prev_eps = 1

    while math.pow(1 + eps, 1 / eps) != 1:
        prev_eps = eps
        eps /= 2

    # formula to calculate e
    # math.pow(1 + eps, 1 / eps) == math.e

    print('\n')
    print('eps =', eps)
    print('prev_eps =', prev_eps)
    print("\n")
    
    return math.pow(1 + prev_eps, 1 / prev_eps)

if __name__ == '__main__':
    print(calc_e())