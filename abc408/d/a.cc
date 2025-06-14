#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> A(N + 1, 0);
    vector<int> B(N + 1, 0);
    vector<int> C(N + 1, 0);
    vector<int> sum(N + 1, 0);
    const int INF = 1e9;
    vector<int> M(N + 1, INF);
    for (int i = 0; i < N; i++) {
      A.at(i + 1) = A.at(i);
      C.at(i + 1) = C.at(i);
      if (S.at(i) == '0') {
        A.at(i + 1)++;
      } else {  // '1'
        C.at(i + 1)++;
      }
    }
    for (int i = N - 1; i >= 0; i--) {
      B.at(i) = B.at(i + 1);
      if (S.at(i) == '1') {
        B.at(i)++;
      }
    }
    for (int i = 0; i <= N; i++) {
      sum.at(i) = A.at(i) + B.at(i);
    }
    M.at(N) = sum.at(N);
    for (int i = N - 1; i >= 0; i--) {
      M.at(i) = min(M.at(i + 1), sum.at(i));
    }
    int ans = INF;
    for (int i = 0; i <= N; i++) {
      int now = M.at(i) - A.at(i) + C.at(i);
      ans = min(ans, now);
    }
    // 1の個数
    int ans1 = count(S.begin(), S.end(), '1');
    ans = min(ans, ans1);
    cout << ans << '\n';
  }
  return 0;
}
