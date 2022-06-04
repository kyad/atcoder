// https://atcoder.jp/contests/abc254/tasks/abc254_d
// O(N log(N)), AC

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> f(N + 1);
  map<int, int> count;  // 平方数で割れるだけ割って同じ数字は同じと思う
  for (int n = 1; n <= N; n++) {
    long long fn = n;
    for (long long x = 2; x * x <= n; x++) {
      while (fn % (x * x) == 0) {
        fn /= (x * x);
      }
    }
    f[n] = fn;
    count[fn]++;
  }
  long long ans = 0;
  for (int n = 1; n <= N; n++) {
    // nを片方に含む組の個数
    ans += count[f[n]];
  }
  cout << ans << endl;
  return 0;
}
