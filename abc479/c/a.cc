#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long W;
  cin >> N >> W;
  vector<long long> A(N);
  vector<long long> B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  int N2 = 1 << N;
  long long ans = 0;
  for (int bit = 0; bit < N2; bit++) {
    long long asum = 0;
    long long bsum = 0;
    for (int i = 0; i < N; i++) {
      if (bit >> i & 1) {
        asum += A.at(i);
        bsum += B.at(i);
      }
    }
    if (bsum <= W) {
      ans = max(ans, asum);
    }
  }
  cout << ans << '\n';
  return 0;
}
