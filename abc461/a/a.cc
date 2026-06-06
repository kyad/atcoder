#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A, D;
  cin >> A >> D;
  bool ans = A <= D;
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}

