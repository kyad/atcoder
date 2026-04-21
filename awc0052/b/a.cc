#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

using lll = __int128;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  lll k = K;
  lll n = N;
  for (int i = 0; i < N; i++) {
    long long ans = (-k + n + i + k * n) % n + 1;
    cout << ans << '\n';
  }
  return 0;
}
