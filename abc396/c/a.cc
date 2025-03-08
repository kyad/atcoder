#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
  }
  vector<long long> W(M);
  for (int j = 0; j < M; j++) {
    cin >> W.at(j);
  }
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  sort(W.begin(), W.end());
  reverse(W.begin(), W.end());
  int N0 = 0;  // Bの0以上の個数 
  for (int i = 0; i < N; i++) {
    if (B.at(i) >= 0) {
      N0++;
    }
  }
  int M0 = 0;  // Wの0以上の個数 
  for (int j = 0; j < M; j++) {
    if (W.at(j) >= 0) {
      M0++;
    }
  }
  if (N0 >= M0) {
    long long ans = 0;
    for (int i = 0; i < N0; i++) {
      ans += B.at(i);
    }
    for (int j = 0; j < M0; j++) {
      ans += W.at(j);
    }
    cout << ans << endl;
  } else {
    long long sum = 0;
    for (int i = 0; i < N0; i++) {
      sum += B.at(i);
      sum += W.at(i);
    }
    long long ans = sum;
    for (int k = N0; k < min(M, N); k++) {
      sum += B.at(k) + W.at(k);
      ans = max(ans, sum);
    }
    cout << ans << endl;
  }
  return 0;
}
