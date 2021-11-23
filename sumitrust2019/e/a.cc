// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_e

#include <iostream>
#include <map>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<int, int> count;
  count[0] = 3;
  long long ans = 1;
  const int MOD = 1000000007;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    ans *= count[A];
    ans %= MOD;
    count[A + 1]++;
    if (count[A] == 1) {
      count.erase(A);
    } else {
      count[A]--;
    }
  }
  cout << ans << endl;
  return 0;
}
