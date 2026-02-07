#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int f(int N) {
  int ans = 0;
  while (N > 0) {
    ans += (N % 10);
    N /= 10;
  }
  return ans;
}

int main() {
  int N, K;
  cin >> N >> K;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (f(i) == K) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
