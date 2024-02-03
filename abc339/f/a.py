from collections import defaultdict
import sys
sys.set_int_max_str_digits(0)


def main():
    N = int(input())
    A = [0] * N
    for i in range(N):
        A[i] = int(input())
    A.sort()
    #print(A)

    cnt = defaultdict(int)
    for a in A:
        cnt[a] += 1
    #print(cnt)

    ans = 0
    MAX = A[N - 1]
    for i in range(N):
        for j in range(N):
            now = A[i] * A[j]
            #print(i, j, now)
            if now > MAX:
                break
            if now in cnt:
                ans += cnt[now]
                #print("OK", cnt[now], ans)

    print(ans)


if __name__ == "__main__":
    main()
