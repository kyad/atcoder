// https://atcoder.jp/contests/arc148/tasks/arc148_c

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> P(N, -1);
  vector<vector<int> > G(N);
  for (int u = 1; u <= N - 1; u++) {
    cin >> P.at(u);
    P.at(u)--;
    G[P.at(u)].push_back(u);
  }

  for (int q = 0; q < Q; q++) {
    int M;
    cin >> M;
    vector<int> S(M);
    for (int m = 0; m < M; m++) {
      cin >> S.at(m);
      S.at(m)--;
    }
    sort(S.begin(), S.end());
    int ans = 0;
    for (auto v : S) {
      int deg = G[v].size();
      ans += (1 + deg);
      if (binary_search(S.begin(), S.end(), P[v])) {  // もし親がSに存在すれば
        ans -= 2;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
