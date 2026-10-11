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
    int now = 0;
    for (int j = i; j < N; j++) {
      if (S.at(j) == 'R') {
        now++;
      } else {
        break;
      }
    }
    ans = max(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
