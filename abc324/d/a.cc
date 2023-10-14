#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long mx = 10000000000000;

vector<int> f(long long x) {
  vector<int> ans;
  while (x > 0) {
    int d = x % 10;
    if (d != 0) {
      ans.push_back(d);
    }
    x /= 10;
  }
  sort(ans.begin(), ans.end());
  return ans;
}

// xをbase進数で見た時の桁数を返す. 0=>0
int digits(long long x, int base = 10) { int d = 0; while (x > 0) { x /= base; d++; } return d; }

int main() {
  map<pair<vector<int>, int>, int> mp;
  for (long long x = 0; x * x < mx; x++) {
    long long sq = x * x;  // 平方数. 0も含むとする
    vector<int> now = f(sq);
    int d = digits(sq);
    mp[make_pair(now, d)]++;
  }

  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> a;
  for (int n = 0; n < N; n++) {
    if (S[n] == '0') {
      continue;
    }
    a.push_back(S[n] - '0');
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int d = 0; d <= N; d++) {
    int now = mp[make_pair(a, d)];
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
