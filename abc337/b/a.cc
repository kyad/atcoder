#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  // 0, 1, 2: Wait A, B, C
  auto f = [&]() -> bool {
    int mode = 0;
    for (int i = 0; i < N; i++) {
      if (mode == 0) {
        if (S[i] == 'A') {
          continue;
        } else if (S[i] == 'B') {
          mode = 1;
          continue;
        } else {
          mode = 2;
          continue;
        }
      } else if (mode == 1) {
        if (S[i] == 'A') {
          return false;
        } else if (S[i] == 'B') {
          continue;
        } else {
          mode = 2;
          continue;
        }
      } else {  // mode == 2
        if (S[i] == 'A') {
          return false;
        } else if (S[i] == 'B') {
          return false;
        } else {
          continue;
        }
      }
    }
    return true;
  };
  bool ans = f();
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
