#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  const int INF = 1e9;
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int N;
    cin >> N;
    vector<int> R(N);
    for (int i = 0; i < N; i++) {
      cin >> R.at(i);
    }
    vector<int> dist(N, INF);  // 確定した高さ
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i = 0; i < N; i++) {
      pq.push(make_pair(R.at(i), i));
    }
    while (!pq.empty()) {
      auto [distu, u] = pq.top();
      pq.pop();
      if (distu > dist.at(u)) {
        continue;  // Garbage
      }
      dist.at(u) = distu;
      const int du[2] = {-1, 1};
      for (int k = 0; k < 2; k++) {
        int v = u + du[k];
        if (v < 0 || v >= N) {
          continue;
        }
        if (distu + 1 < dist.at(v)) {
          dist.at(v) = distu + 1;
          pq.push(make_pair(dist.at(v), v));
        }
      }
    }
    long long ans = 0;
    for (int u = 0; u < N; u++) {
      long long now = R.at(u) - dist.at(u);
      assert(now >= 0);
      ans += now;
    }
    cout << ans << '\n';
  }
  return 0;
}
