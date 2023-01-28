#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  vector<pair<string, int> > sn(N);
  for (int n = 0; n < N; n++) {
    sn[n] = make_pair(S[n], n);
  }
  sort(sn.begin(), sn.end());
  vector<int> ans(N, -1);
  vector<int> len(N - 1, 0);
  for (int n = 0; n < N - 1; n++) {
    string P = sn[n].first;
    string Q = sn[n + 1].first;
    int M = min(P.size(), Q.size());
    for (int m = 0; m < M; m++) {
      if (P[m] == Q[m]) {
        len[n] = m + 1;
      } else {
        break;
      }
    }
  }
  for (int n = 0; n < N; n++) {
    int now = -2;
    if (n < N - 1) {
      now = max(now, len[n]);
    }
    if (n > 0) {
      now = max(now, len[n - 1]);
    }
    ans[sn[n].second] = now;
  }
  for (int i = 0; i < N; i++) {
    assert(ans[i] >= 0);
    cout << ans[i] << '\n';
  }
  return 0;
}
