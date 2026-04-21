#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> K(M);
  vector<vector<int> > S(M);
  vector<int> R(M);
  for (int j = 0; j < M; j++) {
    cin >> K.at(j);
    for (int k = 0; k < K.at(j); k++) {
      int s;
      cin >> s;
      s--;
      S.at(j).push_back(s);
    }
    cin >> R.at(j);
  }

  int N2 = 1<<N;
  const int INF = 1e9;
  int ans = INF;
  for (int bit = 0; bit < N2; bit++) {  // bitが立っている所は感染している
    bool ok = true;  // すべて矛盾していないか
    for (int j = 0; j < M; j++) {
      int now = 0;  // bitの組み合わせでのスキャン結果
      for (int k = 0; k < K.at(j); k++) {
        int i = S.at(j).at(k);
        if (bit>>i&1) {
          now = 1;
        }
      }
      if (now == R.at(j)) {  // 矛盾しない場合
      } else {
        ok = false;
      }
    }
    if (ok) {
      ans = min(ans, __builtin_popcount(bit));
    }
  }
  cout << ans << '\n';
  return 0;
}
