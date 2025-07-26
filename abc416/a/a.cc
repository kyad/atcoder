#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, L, R;
  cin >> N >> L >> R;
  string S;
  cin >> S;
  bool ans = true;
  for (int i = L - 1; i <= R - 1; i++) {
    if (S.at(i) == 'x') {
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
