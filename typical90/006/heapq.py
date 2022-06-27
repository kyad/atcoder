# https://atcoder.jp/contests/typical90/tasks/typical90_f

import heapq

N, K = map(int, input().split())
S = input()

pq = [(s, i) for i, s in enumerate(S[0:N-K+1])]
heapq.heapify(pq)
pos = 0
ans = []
for k in range(K):
    (top_s, top_i) = heapq.heappop(pq)
    ans.append(top_s)
    while pq:
        (s, i) = heapq.heappop(pq)
        if i > top_i:
            heapq.heappush(pq, (s, i))
            break
    if k != K - 1:
        heapq.heappush(pq, (S[N - K + 1 + k], N - K + 1 + k))
print(''.join(ans))
