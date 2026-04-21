// https://atcoder.jp/contests/awc0052/editorial/18705

#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N, M;
  long long F;
  cin >> N >> M >> F;
  vector<long long> R(N);
  for (int i = 0; i < N; i++) {
    cin >> R.at(i);
  }
  vector<vector<pair<int, long long> > > graph(N);
  for (int j = 0; j < M; j++) {
    int U, V;
    long long W;
    cin >> U >> V >> W;
    U--; V--;
    graph.at(U).push_back(make_pair(V, W));
    graph.at(V).push_back(make_pair(U, W));
  }

  int N2 = 1<<N;
  const long long INF = 4e18;
  vector<vector<long long> > dp(N, vector<long long>(N2, -INF));
  int s0 = 1<<0;
  dp.at(0).at(s0) = F + R.at(0);
  priority_queue<tuple<long long, int, int> > q;
  q.push(make_tuple(dp.at(0).at(s0), 0, s0));
  while (!q.empty()) {
    auto [f, u, s] = q.top(); q.pop();
    if (f < dp.at(u).at(s)) {
      continue;
    }
    for (auto [v, w] : graph.at(u)) {
      if (f < w) {
        continue;
      }
      long long nf = f - w;
      int ns = s | (1<<v);
      if ((s>>v&1) == 0) {
        nf += R.at(v);
      }
      if (nf > dp.at(v).at(ns)) {
        dp.at(v).at(ns) = nf;
        q.push(make_tuple(nf, v, ns));
      }
    }
  }
  long long ans = *max_element(dp.at(N - 1).begin(), dp.at(N - 1).end());
  if (ans == -INF) {
    ans = -1;
  }
  cout << ans << '\n';
  return 0;
}
