#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i);
  }
  for (int k = 0; k < N; k++) {
    long long ans;
    if (k == 0 || k == N - 1) {
      ans = (X.at(N - 1) - X.at(0)) / 2;
    } else {
      long long left, right;
      {
        long long t0 = (X.at(k + 1) - X.at(k)) / 2;
        long long t1 = (X.at(k) - X.at(0)) / 2;
        long long t2 = (X.at(N - 1) - X.at(k + 1)) / 2;
        left = t0 + max(t1, t2); // 右から
      }
      {
        long long t0 = (X.at(k) - X.at(k - 1)) / 2;
        long long t1 = (X.at(k - 1) - X.at(0)) / 2;
        long long t2 = (X.at(N - 1) - X.at(k)) / 2;
        right = t0 + max(t1, t2);
      }
      ans = min(left, right);
    }
    cout << ans << '\n';
  }
  return 0;
}
