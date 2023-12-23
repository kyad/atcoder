#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> R(N);
  for (int i = 0; i < N; i++) {
    cin >> R.at(i);
  }
  sort(R.begin(), R.end());
  for (int i = 0; i < N - 1; i++) {
    R.at(i + 1) += R.at(i);
  }
  vector<long long> B(N);
  for (int i = 0; i < N; i++) {
    B[i] = -R[i];
  }
  sort(B.begin(), B.end());
  for (int q = 0; q < Q; q++) {
    long long X;
    cin >> X;
    int ans = B.end() - lower_bound(B.begin(), B.end(), -X);
    cout << ans << '\n';
  }
  return 0;
}
