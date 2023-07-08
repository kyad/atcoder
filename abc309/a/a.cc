#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  A--; B--;
  bool ans = false;
  if (A > B) {
    swap(A, B);
  }
  if (A % 3 == 0 && B % 3 == 1) {
    if (A / 3 == B / 3) {
      ans = true;
    }
  } else if (A % 3 == 1 && B % 3 == 2) {
    if (A / 3 == B / 3) {
      ans = true;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
