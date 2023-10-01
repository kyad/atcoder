// 1<<Nがオーバフローしない限りは正しいはず

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  long long P;
  cin >> N >> K >> P;
  vector<long long> C(N, 0);
  vector<vector<long long> > A(N, vector<long long>(K, 0));
  for (int n = 0; n < N; n++) {
    cin >> C.at(n);
    for (int k = 0; k < K; k++) {
      cin >> A.at(n).at(k);
    }
  }
  int N2 = 1<<N;
  const long long INF = 4e18;
  long long ans = INF;
  for (int bit = 0; bit < N2; bit++) {
    vector<long long> now(K, 0);
    long long cost = 0;
    for (int n = 0; n < N; n++) {
      if (bit>>n&1) {
        cost += C[n];
        for (int k = 0; k < K; k++) {
          now[k] += A[n][k];
        }
      }
    }
    // check
    bool ok = true;
    for (int k = 0; k < K; k++) {
      if (now[k] < P) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = min(ans, cost);
    }
  }
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
