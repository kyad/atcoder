#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<long long, long long> dp;

long long f(long long k) {
  if (dp.count(k) > 0) {
    return dp[k];
  }
  if (k == 0) {
    return dp[k] = 1;
  }
  return dp[k] = (f(k / 2) + f(k / 3));
};

int main() {
  long long N;
  cin >> N;
  long long ans = f(N);
  cout << ans << endl;
  return 0;
}
