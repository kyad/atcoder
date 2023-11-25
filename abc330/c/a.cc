#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long D;
  cin >> D;
  long long mx = 1500000;
  vector<long long> A;
  for (long long i = 0; i <= mx; i++) {
    A.push_back(i * i);
  }
  int N = A.size();
  const long long INF = 4e18;
  long long ans = INF;
  for (long long x2 : A) {
    long long z = D - x2;
    vector<long long>::iterator it = lower_bound(A.begin(), A.end(), z);
    int n = it - A.begin();
    for (int k = -2; k <= 2; k++) {
      int i = n + k;
      if (i < 0 || i >= N) {
        continue;
      }
      long long y2 = A.at(i);
      long long now = abs(x2 + y2 - D);
      ans = min(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}
