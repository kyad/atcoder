#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  bool ans = (a == b) || (b == c) || (c == a);
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
