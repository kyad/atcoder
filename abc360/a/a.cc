#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int r = 100, m = 100;
  for (int i = 0; i < 3; i++) {
    if (S[i] == 'R') {
      r = i;
    } else if (S[i] == 'M') {
      m = i;
    }
  }
  bool ans = r < m;
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
