#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    int A;
    long long B;
    cin >> A >> B;
    if (A < X && B > 0) {
      ans += B;
    }
  }
  cout << ans << '\n';
  return 0;
}
