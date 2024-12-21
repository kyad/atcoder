#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  bool ans = false;
  if (A + B == C) {
    ans = true;
  } else if (B + C == A) {
    ans = true;
  } else if (C + A == B) {
    ans = true;
  } else if (A == B && B == C) {
    ans = true;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
