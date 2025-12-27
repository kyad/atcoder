#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  string T;
  cin >> T;
  const int INF = 1e9;
  int ans = INF;
  for (int i = 0; i <= N - M; i++) {
    int now = 0;
    for (int j = 0; j < M; j++) {
      int a = S.at(i + j) - '0';
      int b = T.at(j) - '0';
      int k;
      if (a >= b) {
        k = a - b;
      } else {
        k = 10 + a - b;
      }
      now += k;
    }
    ans = min(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
