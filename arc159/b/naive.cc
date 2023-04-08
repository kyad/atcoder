#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long naive(long long a, long long b) {
  long long ans = 0;
  while (a >= 1 && b >= 1) {
    long long g = __gcd(a, b);
    a -= g;
    b -= g;
    ans++;
  }
  return ans;
}

int main() {
  long long a, b;
  cin >> a >> b;
  long long ans = naive(a, b);
  cout << ans << endl;
  return 0;
}
