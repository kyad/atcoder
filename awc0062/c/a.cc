#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  long long D;
  cin >> N >> K >> D;
  vector<long long> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  int N2 = 1 << N;
  const long long INF = 4e18;
  long long ans = -INF;
  for (int bit = 0; bit < N2; bit++) {
    long long Asum = 0;
    long long Bsum = 0;
    for (int i = 0; i < N; i++) {
      if (bit >> i & 1) {  // iを注文する
        Asum += A.at(i);
        Bsum += B.at(i);
      }
    }
    long long now = Asum - D * max(0LL, Bsum - K);
    ans = max(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
