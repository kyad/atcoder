#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  long long ans = 0;
  long long total = 0;
  while (true) {
    total += N;
    if (total >= K) {
      break;
    }
    ans++;
    N++;
  }
  cout << ans << '\n';
  return 0;
}
