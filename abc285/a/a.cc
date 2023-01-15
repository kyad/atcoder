#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (b < a) {
    swap(a, b);
  }
  bool ans = false;
  if (a * 2 == b || a * 2 + 1 == b) {
    ans = true;
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
