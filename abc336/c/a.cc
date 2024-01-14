#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N;
  cin >> N;
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  N--;
  // Nを5進数に直す
  vector<long long> rs;
  while (N > 0) {
    long long r = N % 5;
    rs.push_back(r);
    N /= 5;
  }
  reverse(rs.begin(), rs.end());
  string ans;
  for (long long x : rs) {
    ans += '0' + (int)(x * 2);
  }
  cout << ans << endl;
  return 0;
}
