#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string ans;
  for (int i = 0; i <= N; i++) {
    char now = '-';
    for (int j = 1; j <= 9; j++) {
      // 約数かチェック
      if (N % j != 0) {
        continue;
      }
      if (i % (N / j) == 0) {
        now = '0' + j;
        break;
      }
    }
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
