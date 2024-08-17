#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}


int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<int> X(N), A(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i);
    X.at(i)--;
  }
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  // AをZで更新する
  auto f = [&](const vector<int> &Z) {
    vector<int> prev(A);
    for (int i = 0; i < N; i++) {
      A.at(i) = prev.at(Z.at(i));
    }
  };

  // ダブリングテーブル d[m][p]
  const int D = 62;
  vector<vector<int> > d(D, vector<int>(N));
  for (int p = 0; p < N; p++) {
    d[0][p] = X.at(p);
  }
  for (int m = 0; m < D - 1; m++) {
    for (int p = 0; p < N; p++) {
      d[m + 1][p] = d[m][d[m][p]];
    }
  }

  // ダブリングテーブルを使う
  for (int m = D - 1; m >= 0; m--) {
    if ((K >> m) & 1) {
      f(d[m]);
    }
  }

  dumpvec(A);
  return 0;
}
