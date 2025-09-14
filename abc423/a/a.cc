#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int X, C;
  cin >> X >> C;
  int ans = 0;
  for (int a = 0; a <= X; a += 1000) {
    int b = (a / 1000) * C;
    int c = a + b;
    if (c <= X) {
      ans = a;
    }
  }
  cout << ans << endl;
  return 0;
}
