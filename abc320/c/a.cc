#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int M;
  cin >> M;
  vector<string> S(3);
  for (int i = 0; i < 3; i++) {
    cin >> S.at(i);
  }
  const int INF = 1e9;
  int ans = INF;
  for (int k = 0; k <= 9; k++) {  // 合わせる番号
    int P[3] = {0, 1, 2};
    auto sim = [&](int t, int p) { // tから始めてスロットを揃えられる時間
      int ans = -1;
      for (int i = 0; i < M; i++) {
        if (S[p][(t+i)%M] - '0' == k) {
          ans = t + i;
          break;
        }
      }
      return ans;
    };
    do {  // スロットを止める順
      int t = -1;
      for (int i = 0; i < 3; i++) {
        t = sim(t + 1, P[i]);
        if (t < 0) {
          break;
        }
      }
      if (t >= 0) { // 揃えられた時
        ans = min(ans, t);
      }
    } while (next_permutation(P, P + 3));
  }
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
