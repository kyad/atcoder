#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    long long A, B;
    cin >> A >> B;
    if (A * B >= K) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
