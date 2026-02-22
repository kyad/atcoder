#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  long long S, T;
  cin >> S >> T;
  vector<long long> P(M);
  for (int j = 0; j < M; j++) {
    cin >> P.at(j);
  }
  int M2 = 1<<M;
  // dp[s]: sを全部通る時の最小値
  const long long INF = 4e18;
  vector<long long> dp(M2, INF);
  auto dec = [&N](long long p) -> pair<int, int> {
    return make_pair((p - 1) / N, (p - 1) % N);
  };
  auto dist = [&dec](long long p, long long q) -> long long {
    auto [py, px] = dec(p);
    auto [qy, qx] = dec(q);
    return abs(py - qy) + abs(px - qx);
  };
  dp.at(0) = dist(S, T);
  // paths[s]: 最小値の時のパス達
  vector<set<vector<long long> > > paths(M2);
  vector<long long> path0;
  path0.push_back(S);
  path0.push_back(T);
  paths.at(0).insert(path0);
  // 配るdp
  for (int s = 0; s < M2; s++) {
    // p: 追加する点
    for (int j = 0; j < M; j++) {
      if (s>>j&1) {  // 既に通っている
        continue;
      }
      int ns = s | (1<<j);
      long long p = P.at(j);
      // dp.at(ns), paths.at(ns)を更新する
      for (const vector<long long>& path : paths.at(s)) {
        int K = path.size();
        for (int k = 0; k < K - 1; k++) {  // kとk+1の間に点を入れる
          long long q = path.at(k);
          long long r = path.at(k + 1);
          long long cand = dp.at(s) + dist(q, p) + dist(p, r) - dist(q, r);
          if (cand <= dp.at(ns)) {
            vector<long long> npath(path);
            npath.insert(npath.begin() + k + 1, p);
            if (cand < dp.at(ns)) {
              dp.at(ns) = cand;
              paths.at(ns).clear();
            }
            paths.at(ns).insert(npath);
          }
        }
      }
    }
  }
  long long ans = dp.at(M2 - 1);
  cout << ans << '\n';
  return 0;
}
