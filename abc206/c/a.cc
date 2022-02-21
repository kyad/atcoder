// https://atcoder.jp/contests/abc206/tasks/abc206_c

#include <iostream>
#include <map>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<int, int> mp;
  long long ans = 0;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    ans += (long long)(n - mp[A]);
    mp[A]++;
  }
  cout << ans << endl;
  return 0;
}
