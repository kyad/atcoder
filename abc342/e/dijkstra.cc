#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

const long long INF = 4e18;

/**
 * Dijkstra's algorithm
 * 計算量：(O|E|log|V|)
 * 使用例：
 *   vector<long long> dist = dijstra(graph, start);
 *   long long ans = *min_element(dist.begin(), dist.end());
 */
vector<long long> dijkstra(vector<vector<tuple<int, long long, long long, long long, long long> > > graph, int start)  {
  int N = graph.size();
  vector<long long> f(N, -INF);
  priority_queue<pair<long long, int> > pq;
  f.at(start) = INF;
  pq.push(make_pair(INF, start));
  while (!pq.empty()) {
    long long fu = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (fu < f.at(u)) {
      continue;  // Garbage
    }
    for (tuple<int, long long, long long, long long, long long> p : graph.at(u)) {
      int v = get<0>(p);
      long long l = get<1>(p);
      long long d = get<2>(p);
      long long k = get<3>(p);
      long long c = get<4>(p);
      // uを通る場合のf[v]を求める。
      if (fu - c < l) {
        // vからは到達できない。
      } else {
        long long fv = l + ((fu - c - l) / d) * d;
        long long r = l + d * (k - 1);
        fv = min(fv, r);
        chmax(f[u], fv);
        if (fv > f.at(v)) {  // もし更新したならば
          f.at(v) = fv;
          pq.push(make_pair(fv, v));
        }
      }
    }
  }
  return f;
}

int main() {
  int N, M;
  cin >> N >> M;
  // A -> B, L, D, K, C
  vector<vector<tuple<int, long long, long long, long long, long long> > > rgraph(N);
  for (int m = 0; m < M; m++) {
    long long L, D, K, C;
    int A, B;
    cin >> L >> D >> K >> C >> A >> B;
    A--; B--;
    if (A == N - 1) {
      // N-1から出る電車は考えなくて良い
      continue;
    }
    rgraph[B].push_back(make_tuple(A, L, D, K, C));
  }
  vector<long long> f = dijkstra(rgraph, N - 1);
  for (int u = 0; u < N - 1; u++) {
    if (f[u] == -INF) {
      cout << "Unreachable" << '\n';
    } else {
      cout << f[u] << '\n';
    }
  }
  return 0;
}
