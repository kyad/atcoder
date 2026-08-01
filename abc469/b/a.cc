#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int now = 1;
    if (S.at(i) == 'o') {
      now = 0;
    }
    if (i >= 1 && S.at(i - 1) == 'o') {
      now = 0;
    }
    if (i <= N - 2 && S.at(i + 1) == 'o') {
      now = 0;
    }
    ans += now;
  }
  cout << ans << '\n';
  return 0;
}
