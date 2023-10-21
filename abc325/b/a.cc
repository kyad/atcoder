#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// 2d-matrix
template<class T> ostream& operator<<(ostream& os, const vector<vector<T> > &v) {
  int y0 = 0;
  int y1 = (int)v.size() - 1;
  for (int i = y0; i <= y1; i++) {
    os << (i == 0 ? "[[" : " [");
    int x0 = 0;
    int x1 = (int)v[i].size() - 1;
    for (int j = x0; j <= x1; j++) {
      os << v[i][j];
      if (j != x1) {
        os << ' ';
      }
    }
    os << (i == y1 ? "]]" : "]\n");
  }
  return os;
}

int main() {
  // work[i][j]: 時差iの拠点がj時からは勤務時間中か
  vector<vector<bool> > work(24, vector<bool>(24, false));
  for (int i = 0; i < 24; i++) {
    int start = 9 + i;
    for (int k = 0; k < 9; k++) {
      int j = (start + k) % 24;
      work[i][j] = true;
    }
  }

  int N;
  cin >> N;
  vector<long long> W(N);
  vector<int> X(N);
  for (int n = 0; n < N; n++) {
    cin >> W.at(n) >> X.at(n);
  }
  long long ans = 0;
  for (int start = 0; start < 24; start++) {
    for (int len = 0; len <= 8; len++) {
      long long now = 0;
      for (int n = 0; n < N; n++) {
        bool ok = true;
        for (int j = start; j <= (start + len); j++) {
          int jj = j % 24;
          if (!work[X.at(n)][jj]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          now += W.at(n);
        }
      }
      ans = max(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}
