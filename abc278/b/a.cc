#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool f(int n) {
  int h = n / 60;
  int m = n % 60;
  int A = h / 10;
  int B = h % 10;
  int C = m / 10;
  int D = m % 10;
  int nh = A * 10 + C;
  int nm = B * 10 + D;
  return nh <= 23 && nm <= 59;
}

int main() {
  int H, M;
  cin >> H >> M;
  int N = 24 * 60;
  int n = H * 60 + M;
  while (true) {
    if (f(n)) {
      break;
    }
    n = (n + 1) % N;
  }
  int h = n / 60;
  int m = n % 60;
  cout << h << ' ' << m << endl;
  return 0;
}
