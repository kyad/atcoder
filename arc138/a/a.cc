// https://atcoder.jp/contests/arc138/tasks/arc138_a

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(K);
  for (int k = 0; k < K; k++) {
    cin >> A.at(k);
  }
  int M = N - K;
  vector<int> B(M);
  for (int m = 0; m < M; m++) {
    cin >> B.at(m);
  }
  map<int, int> mp;
  int mx = -1;
  for (int m = 0; m < M; m++) {
    if (B[m] > mx) {
      mx = B[m];
      mp[B[m]] = m;
    }
  }
  const int INF = 400001;
  int ans = INF;
  for (int k = 0; k < K; k++) {
    auto it = mp.upper_bound(A[k]);
    if (it != mp.end()) {
      int p = it->second;
      int dist = p + (K - k);
      ans = min(ans, dist);
    }
  }
  cout << (ans == INF ? -1 : ans) <<endl;
  return 0;
}
