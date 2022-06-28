# https://atcoder.jp/contests/abc257/tasks/abc257_f

import queue

N, M = map(int, input().split())
graph = [[] for n in range(N + 1)]  # 1-indexed
for m in range(M):
    U, V = map(int, input().split())
    graph[U].append(V)
    graph[V].append(U)

A = {}
INF = 3 * 10**5 + 2
A[1] = [INF] * (N + 1)  # 1からの最短距離
A[N] = [INF] * (N + 1)  # Nからの最短距離
for start in (1, N):
    dist = A[start]
    dist[start] = 0
    todo = queue.Queue()
    todo.put(start)
    while not todo.empty():
        u = todo.get()
        for v in graph[u]:
            if dist[v] == INF:
                dist[v] = dist[u] + 1
                todo.put(v)
ans = []
for i in range(1, N + 1):
    now = min(A[1][N], A[1][0] + A[N][i], A[1][i] + A[N][0])
    ans.append(-1 if now >= INF else now)
print(' '.join(map(str, ans)))
