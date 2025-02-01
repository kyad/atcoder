// https://atcoder.jp/contests/abc391/editorial/12102

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
    X.at(i)--;
  }
  vector<vector<int> > ys(W);
  for (int i = 0; i < N; i++) {
    ys.at(X.at(i)).push_back(Y.at(i));
  }
  for (int x = 0; x < W; x++) {
    sort(ys.at(x).begin(), ys.at(x).end());
  }

  // d[i]: i(i>=0)番目の消滅時刻
  vector<int> d(N + 1, 0);
  for (int x = 0; x < W; x++) {
    int c = ys.at(x).size();
    for (int i = 0; i < c; i++) {
      d.at(i) = max(d.at(i), ys.at(x).at(i));
    }
    d.at(c) = INF;  // 消えない
  }
  for (int i = 0; i <= N; i++) {
    if (d.at(i) == INF) {
      for (int j = i + 1; j <= N; j++) {
        d.at(j) = INF;
      }
      break;
    }
  }

  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int T, A;
    cin >> T >> A;
    A--;
    // i: ブロックAが下から何番目か(i>=0)
    int x = X.at(A);
    int y = Y.at(A);
    int i = lower_bound(ys.at(x).begin(), ys.at(x).end(), y) - ys.at(x).begin();
    if (T >= d.at(i)) {
      cout << "No" << '\n';
    } else {
      cout << "Yes" << '\n';
    }
  }
  return 0;
}
