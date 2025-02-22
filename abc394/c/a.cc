#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  string ans(S);
  int mode = 0;  // 前がWなら1
  int w0 = -1;
  for (int i = 0; i < N; i++) {
    char c = S.at(i);
    if (mode == 0) {
      if (c == 'W') {
        w0 = i;
        mode = 1;
      }
    } else {
      if (c == 'W') {
      } else if (c == 'A') {
        ans.at(w0) = 'A';
        for (int j = w0 + 1; j <= i; j++) {
          ans.at(j) = 'C';
        }
        mode = 0;
      } else {
        mode = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
