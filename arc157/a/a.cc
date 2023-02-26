#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  bool ans;
  if (B == 0 && C == 0) {
    ans = A * D == 0;
  } else {
    ans = abs(B - C) <= 1;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
