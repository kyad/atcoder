// https://atcoder.jp/contests/abc128/tasks/abc128_c

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool> > s(M, vector<bool>(N, false));
  for (int m = 0; m < M; m++) {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      int _s;
      cin >> _s;
      s[m][_s - 1] = true;
    }
  }
  vector<int> p(M);
  for (int m = 0; m < M; m++) {
    cin >> p[m];
  }
  int ans = 0;
  for (int bit = 0; bit < 1<<N; bit++) {
    bool ok = true;
    for (int m = 0; m < M; m++) {
      int count = 0;
      for (int n = 0; n < N; n++) {
        if (!s[m][n]) {
          continue;
        }
        if ((bit>>n) & 1) {
          count++;
        }
      }
      if (count % 2 != p[m]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
