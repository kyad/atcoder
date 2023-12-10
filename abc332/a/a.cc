#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long S, K;
  cin >> N >> S >> K;
  long long ans = 0;
  for (int n = 0; n < N; n++) {
    long long P, Q;
    cin >> P >> Q;
    ans += P * Q;
  }
  if (ans < S) {
    ans += K;
  }
  cout << ans << endl;
  return 0;
}
