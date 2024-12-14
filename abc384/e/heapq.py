# import pypyjit
import sys
import heapq

# pypyjit.set_param("max_unroll_recursion=-1")
sys.set_int_max_str_digits(0)
sys.setrecursionlimit(10**6)


def main():
    H, W, X = map(int, input().split())
    P, Q = map(int, input().split())
    P -= 1
    Q -= 1
    S = []
    for y in range(H):
        line = list(map(int, input().split()))
        S.append(line)

    seen = [[False] * W for y in range(H)]

    q = [[S[P][Q], P, Q]]
    seen[P][Q] = True

    heapq.heapify(q)

    dy = [0, +1, 0, -1]
    dx = [+1, 0, -1, 0]

    strength = 0

    while len(q) > 0:
        [s, y, x] = heapq.heappop(q)
        if strength == 0 or X * s < strength:
            strength += s
            for k in range(4):
                ny = y + dy[k]
                nx = x + dx[k]
                if ny < 0 or ny >= H or nx < 0 or nx >= W or seen[ny][nx]:
                    continue
                ns = S[ny][nx]
                heapq.heappush(q, [ns, ny, nx])
                seen[ny][nx] = True
        else:
            break
    print(strength)

if __name__ == "__main__":
    main()
