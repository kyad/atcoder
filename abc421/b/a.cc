#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long f(long long X) {
  long long ans = 0;
  while (X > 0) {
    long long r = X % 10;
    ans *= 10;
    ans += r;
    X /= 10;
  }
  return ans;
}

int main() {
  long long X, Y;
  cin >> X >> Y;
  vector<long long> A(11, 0);
  A.at(1) = X;
  A.at(2) = Y;
  for (int i = 3; i <= 10; i++) {
    A.at(i) = f(A.at(i - 1) + A.at(i - 2));
  }
  long long ans = A.at(10);
  cout << ans << endl;
  return 0;
}
