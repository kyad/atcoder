import sys

def main():
    N = int(sys.stdin.readline())
    S = list(map(int, sys.stdin.readline().split()))
    T = list(map(int, sys.stdin.readline().split()))
    start = T.index(min(T))
    ans = [0] * N
    for n in range(N):
        if n == 0:
            ans[start] = T[start]
        else:
            ans[(start + n) % N] = min(ans[(start + n - 1) % N] + S[(start + n - 1) % N], T[(start + n) % N])
    for n in range(N):
        print(ans[n])

if __name__ == '__main__':
    main()
