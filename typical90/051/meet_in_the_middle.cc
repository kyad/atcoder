#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  long long P;
  cin >> N >> K >> P;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  if (N == 1) {
    assert(K == 1);
    cout << (A[0] <= P) << endl;
    return 0;
  }
  vector<long long> B;
  for (int n = 0; n < N / 2; n++) {
    B.push_back(A[n]);
  }
  vector<long long> C;
  for (int n = N / 2; n < N; n++) {
    C.push_back(A[n]);
  }
  auto f = [](vector<long long> B) -> vector<vector<long long> > {
    int M = B.size();
    vector<vector<long long> > ans(M + 1);
    for (int b = 0; b < 1<<M; b++) {
      long long now = 0;
      for (int m = 0; m < M;  m++) {
        if (b>>m&1) {
          now += B[m];
        }
      }
      int k = __builtin_popcount(b);
      assert(0 <= k && k <= M);
      ans[k].push_back(now);
    }
    for (int k = 0; k <= M; k++) {
      sort(ans[k].begin(), ans[k].end());
    }
    return ans;
  };
  vector<vector<long long> > S = f(B);
  vector<vector<long long> > T = f(C);
  long long ans = 0;
  for (int k = 0; k <= K; k++) {
    if (k >= (int)S.size()) {
      continue;
    }
    int l = K - k;
    if (l < 0 || l >= (int)T.size()) {
      continue;
    }
    for (long long s : S[k]) {
      long long x = P - s;
      long long now = upper_bound(T[l].begin(), T[l].end(), x) - T[l].begin();
      ans += now;
    }
  }
  cout << ans << endl;
  return 0;
}
