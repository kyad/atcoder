#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int a = A * 100 + B;
  int c = C * 100 + D;
  bool ans;
  if (a > c) {
    ans = true;
  } else {
    ans = false;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
