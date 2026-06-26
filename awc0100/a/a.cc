#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    long long A, T;
    cin >> A >> T;
    ans += A * T;
  }
  cout << ans << '\n';
  return 0;
}
