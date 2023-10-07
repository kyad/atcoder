#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  for (int m = 0; m < M; m++) {
    cin >> A.at(m);
  }
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  // sum[i]: 現時点でiの合計得点
  vector<int> sum(N, 0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (S[i][j] == 'o') {
        sum[i] += A[j];
      }
    }
  }
  
  auto solve = [&](int n) {
    // 目標得点mxはn以外の最大値
    int mx = -1;
    for (int i = 0; i < N; i++) {
      if (i == n) continue;
      mx = max(mx, sum[i] + i);
    }
    vector<int> B;
    for (int j = 0; j < M; j++) {
      if (S[n][j] == 'x') {
        B.push_back(A[j]);
      }
    }
    sort(B.rbegin(), B.rend());
    int ans = 0;
    // scoreがmxを越えるまで繰り返す
    int score = n + sum[n];
    for (int b : B) {
      if (score > mx) continue;
      score += b;
      ans++;
    }
    assert(score > mx);
    return ans;
  };
  for (int n = 0; n < N; n++) {
    int ans = solve(n);
    cout << ans << '\n';
  }
  return 0;
}
