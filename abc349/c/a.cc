#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S, T;
  cin >> S;
  cin >> T;
  auto f = [&]() -> int {
    int j = 0;  // Tのindex
    for (char s: S) {
      int ss = s - 'a';
      int tt = T[j] - 'A';
      if (ss == tt) {
        j++;
      }
      if (j >= 3) {
        break;
      }
    }
    return j;
  };
  bool ans;
  int now = f();
  if (T[2] == 'X') {
    ans = (now >= 2);
  } else {
    ans = (now >= 3);
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
