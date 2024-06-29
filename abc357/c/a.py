import numpy as np
import sys

sys.set_int_max_str_digits(0)
sys.setrecursionlimit(10**6)


def dump(S: np.ndarray):
    for row in S:
        print(''.join(row))


def main():
    N = int(input())
    S = [None for i in range(N + 1)]
    S[0] = np.array(['#'])
    for i in range(N):
        mid = np.full((3**i, 3**i), '.')
        S[i + 1] = np.block([[S[i], S[i], S[i]],
                             [S[i],  mid, S[i]],
                             [S[i], S[i], S[i]]])
    dump(S[N])


if __name__ == "__main__":
    main()
