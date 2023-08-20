#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long K;
  cin >> K;
  long long ans = 0;
  for (long long a = 1; a * a * a <= K; a++) {
    for (long long b = a; a * b * b <= K; b++) {
      long long ab = a * b;
      if (K % ab != 0) {
        continue;
      }
      long long c = K / ab;
      if (b <= c) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
