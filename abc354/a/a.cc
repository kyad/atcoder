#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long H;
  cin >> H;
  long long d = 1;
  long long l = 0;
  for (int i = 0; i < 40; i++) {
    if (l > H) {
      cout << i << endl;
      return 0;
    }
    l += d;
    d <<= 1LL;
  }
  return 1;
}
