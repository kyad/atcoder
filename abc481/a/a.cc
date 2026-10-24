#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// xをbase進数で見た時の桁数を返す
int digits(long long x, int base) { int d = 0; while (x > 0) { x /= base; d++; } return d; }

int main() {
  int A, B;
  cin >> A >> B;
  int ans = digits(A + B, 10);
  cout << ans << '\n';
  return 0;
}
