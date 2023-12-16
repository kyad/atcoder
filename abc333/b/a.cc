#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S, T;
  cin >> S;
  cin >> T;
  int ds = (S[0] - S[1] + 5) % 5;
  int dt = (T[0] - T[1] + 5) % 5;
  bool s = (ds == 1) || (ds == 4);
  bool t = (dt == 1) || (dt == 4);
  bool ans = s == t;
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
