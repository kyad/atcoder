#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  bool ans = (A != B) && (B == C);
  cout << (ans ? "Yes" : "No") << '\n';

  return 0;
}
