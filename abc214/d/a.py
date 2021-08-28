import sys

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

def main():
    N = int(sys.stdin.readline())
    #graph = [[] for n in range(n)]
    edges = []
    for n in range(N - 1):
        u, v, w = map(int, sys.stdin.readline().split())
        edges.append((w, u - 1, v - 1))
        #graph[u - 1].append((v - 1, w))
        #pgraph[v - 1].append((u - 1, w))
    edges.sort()
    uf = UnionFind(N)
    S = [0] * N
    for i, (w, u, v) in enumerate(edges):
        size1 = uf.size(u)
        size2 = uf.size(v)
        S1 = S[uf.root(u)]
        S2 = S[uf.root(v)]
        uf.unite(u, v)
        S[uf.root(u)] = S1 + S2 + size1 * size2 * w
        #print('i=', i, u, v, w, 'size1=', size1, 'size2=', size2, 'S=', S)
    print(S[uf.root(0)])

if __name__ == '__main__':
    main()
