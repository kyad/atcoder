#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    if (A > X) {
      ans += A - X;
    }
  }
  cout << ans << '\n';
  return 0;
}
