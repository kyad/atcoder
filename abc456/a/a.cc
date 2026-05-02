#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int X;
  cin >> X;
  bool ans;
  if (3 <= X && X <= 18) {
    ans = true;
  } else {
    ans = false;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
