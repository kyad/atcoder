#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N = 5;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  int ans = N;
  // 横
  for (int i = 0; i < N; i++) {
    int c = count(S.at(i).begin(), S.at(i).end(), 'o');
    int now = N - c;
    ans = min(ans, now);
  }
  // 縦
  for (int x = 0; x < N; x++) {
    int c = 0;
    for (int y = 0; y < N; y++) {
      if (S.at(y).at(x) == 'o') {
        c++;
      }
    }
    int now = N - c;
    ans = min(ans, now);
  }
  // 斜め
  {
    int c = 0;
    for (int i = 0; i < N; i++) {
      if (S.at(i).at(i) == 'o') {
        c++;
      }
    }
    int now = N - c;
    ans = min(ans, now);
  }
  {
    int c = 0;
    for (int y = 0; y < N; y++) {
      int x = N - 1 - y;
      if (S.at(y).at(x) == 'o') {
        c++;
      }
    }
    int now = N - c;
    ans = min(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
