# https://atcoder.jp/contests/typical90/tasks/typical90_l

class UnionFind:
    def __init__(self, N):
        self.parent = [-1] * N
        self._size = [1] * N

    def root(self, x):
        if self.parent[x] == -1:
            return x;
        else:
            ans = self.root(self.parent[x])
            self.parent[x] = self.root(self.parent[x])
            return ans

    def issame(self, x, y):
        return self.root(x) == self.root(y)

    def unite(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return False
        else:
            if self._size[x] < self._size[y]:
                x, y = y, x  # Union by size
            self.parent[y] = x
            self._size[x] += self._size[y]
            return True

    def size(self, x):
        return self._size[self.root(x)]

H, W = map(int, input().split())
red = [[False] * W for y in range(H)]

def encode(r, c):
    return r * W + c

N = H * W
uf = UnionFind(N)

dr = [-1, 0, 1, 0]
dc = [0, -1, 0, 1]

Q = int(input())
for q in range(Q):
    line = list(map(int, input().split()))
    if line[0] == 1:
        r, c = line[1:]
        r -= 1
        c -= 1
        red[r][c] = True
        for k in range(4):
            nr = r + dr[k]
            nc = c + dc[k]
            if nr < 0 or nr >= H or nc < 0 or nc >= W:
                continue
            if red[nr][nc]:
                uf.unite(encode(r, c), encode(nr, nc))
    else:
        ra, ca, rb, cb = line[1:]
        ra -= 1
        ca -= 1
        rb -= 1
        cb -= 1
        if red[ra][ca] and red[rb][cb] and uf.issame(encode(ra, ca), encode(rb, cb)):
            print('Yes')
        else:
            print('No')
