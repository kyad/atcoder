#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  bool ans = false;
  if (C < B) {
    if (C < A && A < B) {
      ans = true;
    }
  } else {
    if (A < B || C < A) {
      ans = true;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
