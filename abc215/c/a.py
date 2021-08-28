import sys
import itertools

def main():
    S, K = sys.stdin.readline().split()
    K = int(K)
    S = sorted(S)
    count = 0
    memo = {}
    for x in itertools.permutations(S):
        if x in memo:
            continue
        memo[x] = 1
        count = count + 1
        if count == K:
            break
    print(''.join(x))

if __name__ == '__main__':
    main()
