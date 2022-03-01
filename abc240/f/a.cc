// https://atcoder.jp/contests/abc240/tasks/abc240_f

#include <iostream>
#include <vector>
using namespace std;

void testcase() {
  int N, M;
  cin >> N >> M;
  vector<int> X(N), Y(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n) >> Y.at(n);
  }
  long long ans = X[0];
  long long Bsum = 0;
  long long Asum = 0;
  for (int n = 0; n < N; n++) {
    long long Bsum_next = Bsum + (long long)X[n] * Y[n];
    if (Bsum > 0 && Bsum_next < 0) {
      long long k = Bsum / (-X[n]);
      long long dA = Bsum * k + (long long)X[n] * k * (k + 1) / 2;
      ans = max(ans, Asum + dA);
    }
    long long dA = Bsum * Y[n] + (long long)X[n] * Y[n] * (Y[n] + 1) / 2;
    Bsum = Bsum_next;
    Asum += dA;
    ans = max(ans, Asum);
  }
  ans = max(ans, Asum);  // Also, check Bsum = 0 --> Bsum_next < 0, Bsum > 0 --> Bsum_next = 0
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    testcase();
  }
  return 0;
}
