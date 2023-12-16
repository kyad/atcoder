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
  cin >> N;
  vector<int> T(N), X(N);
  for (int n = 0; n < N; n++) {
    cin >> T.at(n) >> X.at(n);
  }
  vector<int> A(N, -1);  // 時刻nでポーションを取る:1、取らない:0
  vector<int> M(N, 0);  // モンスターxが出た数
  for (int n = N - 1; n >= 0; n--) {
    int x = X.at(n);
    if (T.at(n) == 1) {  // ポーション
      if (M[x] > 0) {
        M[x]--;
        A[n] = 1;
      } else {
        A[n] = 0;
      }
    } else {  // モンスター
      M[x]++;
    }
  }
  // NGケース
  for (int x = 0; x < N; x++) {
    if (M[x] > 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  // シミュレーション
  vector<int> ans;
  const int INF = 1e9;
  int K = -INF;
  int have = 0;
  vector<int> count(N, 0);  // ポーションxの数
  for (int n = 0; n < N; n++) {
    int x = X.at(n);
    if (T.at(n) == 1) {  // ポーション
      if (A.at(n) == 1) {
        have++;
        count[x]++;
      }
      ans.push_back(A.at(n));
    } else {  // モンスター
      if (count[x] <= 0) {
        cout << -1 << endl;
        return 0;
      }
      have--;
      count[x]--;
    }
    assert(have >= 0);
    K = max(K, have);
  }
  cout << K << endl;
  dumpvec(ans);
  return 0;
}
