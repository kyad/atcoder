// https://atcoder.jp/contests/abc225/tasks/abc225_f

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  vector<int> a(N);
  for (int n = 0; n < N; n++) {
    a.at(n) = n;
  }
  string ans = "z";
  ans[0] += 1;
  do {
    string now = "";
    for (int k = 0; k < K; k++) {
      now += S.at(a[k]);
    }
    ans = min(ans, now);
  } while (next_permutation(a.begin(), a.end()));
  cout << ans << endl;
  return 0;
}
