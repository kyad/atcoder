#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int INF = 2e9;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) + 1 << " \n"[n + 1 == N];
  }
}

int main() {
  int N;
  cin >> N;
  map<int, vector<pair<int, int> > > mp;
  for (int i = 0; i < N; i++) {
    int a, c;
    cin >> a >> c;
    mp[a].emplace_back(c, i);
  }
  for (auto [a, cs]: mp) {
    sort(cs.begin(), cs.end());
    reverse(cs.begin(), cs.end());
  }
  int cmax = INF;
  vector<int> ans;
  for (map<int, vector<pair<int, int> > >::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++) {
    for (auto ci : it->second) {
      int c = ci.first;
      int i = ci.second;
      if (c > cmax) {
        continue;
      } else {
        cmax = min(cmax, c);
        ans.push_back(i);
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  dumpvec(ans);
  return 0;
}
