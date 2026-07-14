#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int ans = 0;
  int now = 0;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    if (A >= K) {
      now++;
      ans = max(now, ans);
    } else {
      now = 0;
    }
  }
  cout << ans << '\n';
  return 0;
}
