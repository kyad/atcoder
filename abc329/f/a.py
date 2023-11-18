import sys
sys.set_int_max_str_digits(0)


def main():
    N, Q = map(int, input().split())
    C = list(map(int, input().split()))
    # 集合
    S = []
    for n in range(N):
        now = set()
        now.add(C[n])
        S.append(now)
    for q in range(Q):
        A, B = map(int, input().split())
        A -= 1
        B -= 1
        sa = len(S[A])
        sb = len(S[B])
        if sa <= sb:  # sa -> sb
            S[B] |= S[A]
            S[A] = set()
        else:  # sa <- sb
            S[A] |= S[B]
            S[B] = S[A]
            S[A] = set()
        print(len(S[B]))

if __name__ == "__main__":
    main()
