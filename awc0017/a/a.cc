#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    int C;
    long long D;
    cin >> C >> D;
    if (C <= K) {
      ans += D;
    }
  }
  cout << ans << '\n';
  return 0;
}
