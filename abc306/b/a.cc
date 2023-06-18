#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N = 64;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  unsigned long long ans = 0;
  unsigned long long base = 1;
  for (int n = 0; n < N; n++) {
    ans += base * A[n];
    base *= 2;
  }
  cout << ans << endl;
  return 0;
}
