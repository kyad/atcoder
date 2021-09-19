// https://atcoder.jp/contests/arc124/tasks/arc124_a

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<set<int> > s(N);
  for (int n = 0; n < N; n++) {
    for (int i = 0; i < K; i++) {
      s[n].insert(i);
    }
  }
  vector<bool> fixed(N, false);
  for (int i = 0; i < K; i++) {
    char c;
    int k;
    cin >> c >> k;
    k--;
    fixed[k] = true;
    if (c == 'L') {
      for (int n = 0; n < k; n++) {
        s[n].erase(i);
      }
    } else {
      for (int n = k + 1; n < N; n++) {
        s[n].erase(i);
      }
    }
  }
  long long ans = 1;
  for (int n = 0; n < N; n++) {
    if (fixed[n]) {
      continue;
    }
    ans *= s[n].size();
    ans %= 998244353;
  }
  cout << ans << endl;
  return 0;
}
  
