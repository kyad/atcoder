#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  sort(A.begin(), A.end());
  vector<long long> B(M, 0);
  for (int m = 0; m < M; m++) {
    B.at(m) += A.at(N - M + m);
  }
  for (int m = 0; m < N - M; m++) {
    B.at(m) += A.at(N - M - 1 - m);
  }
  long long ans = 0;
  for (int m = 0; m < M; m++) {
    ans += B.at(m) * B.at(m);
  }
  cout << ans << endl;
  return 0;
}
