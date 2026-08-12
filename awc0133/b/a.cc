#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K, T;
  cin >> N >> K >> T;
  long long ans = 0;
  vector<long long> A;
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    if (i == T - 1) {
      ans += a;
    } else {
      A.push_back(a);
    }
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  for (int i = 0; i < K - 1; i++) {
    ans += A.at(i);
  }
  cout << ans << '\n';
  return 0;
}
