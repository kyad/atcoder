// https://atcoder.jp/contests/abc246/tasks/abc246_f

#include <iostream>
#include <vector>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
  int N, L;
  cin >> N >> L;
  vector<bool> used(26, false);
  mint ans = 0;
  for (int n = 0; n < N; n++) {
    string S;
    cin >> S;
    size_t len = S.size();
    mint temp = len;
    ans += temp.pow(L);

    temp = 0;
    for (size_t i = 0; i < len; i++) {
      if (used.at(S.at(i) - 'a')) {
        temp++;
      }
    }
    ans -= temp.pow(L);
    // Update used
    for (size_t i = 0; i < len; i++) {
      used.at(S.at(i) - 'a') = true;
    }
  }
  cout << ans.val() << endl;
  return 0;
}
