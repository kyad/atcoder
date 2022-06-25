// https://atcoder.jp/contests/abc257/tasks/abc257_c

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> W(N);
  for (int n = 0; n < N; n++) {
    cin >> W.at(n);
    W.at(n) *= 2;
  }
  const int INF = 2000000002;
  map<int, pair<int, int> > mp;  // w -> (child, adult)
  int C = 0;
  int D = 0;
  for (int n = 0; n < N; n++) {
    if (S[n] == '0') {
      mp[W[n]].first++;
      C++;
    } else {
      mp[W[n]].second++;
      D++;
    }
  }
  mp[0].first = 0;
  mp[0].second = 0;
  mp[INF].first = 0;
  mp[INF].second = 0;
  int ans = 0;
  int c = 0;  // 今以上の子供の人数
  int d = 0;  // 今以上の大人の人数
  for (map<int, pair<int, int> >::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++) {
    c += it->second.first;
    d += it->second.second;
    int now = d + (C - c);
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}
