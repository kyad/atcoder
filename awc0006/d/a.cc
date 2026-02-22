#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int> > LR(M);
  for (int i = 0; i < M; i++) {
    cin >> LR.at(i).first >> LR.at(i).second;
  }
  sort(LR.begin(), LR.end());
  int c = 0;  // どこまでカバーできたか
  int i = 0;
  int ans = 0;
  while (true) {
    int nc = -1;  // 次に最大カバーできるところ
    while (i < M) {
      int l = LR.at(i).first;
      int r = LR.at(i).second;
      if (l <= c + 1) {
        nc = max(nc, r);
        i++;
      } else {
        break;
      }
    }
    if (nc == -1) {  // それ以上連続でカバーできなくなった
      break;
    }
    c = nc;
    ans++;
    if (c >= N) {
      break;
    }
  }
  if (c < N) {
    cout << -1 << endl;
  } else {
    cout << ans << '\n';
  }
  return 0;
}
