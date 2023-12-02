#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> T ceildiv(T a, T b) {
  return (a + b - 1) / b;
}

int main() {
  int N;
  cin >> N;
  long long S, M, L;
  cin >> S >> M >> L;
  const long long INF = 4e18;
  long long ans = INF;
  for (int a = 0; a <= ceildiv(N, 6); a++) {
    for (int b = 0; b <= ceildiv(N, 8); b++) {
      for (int c = 0; c <= ceildiv(N, 12); c++) {
        if (a * 6 + b * 8 + c * 12 < N) {
          continue;
        }
        long long now = S * a + M * b + L * c;
        ans = min(ans, now);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
