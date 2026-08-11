#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> ss;
  map<int, vector<int>> mp;
  for (int i = 0; i < N; i++) {
    int S;
    int C;
    cin >> S >> C;
    ss.push_back(S);
    mp[S].push_back(C);
  }
  sort(ss.begin(), ss.end());
  long long ans = 0;
  int M = ss.size();
  set<int> used;
  for (int i = 0; i < M; i++) {
    int S = ss.at(i);
    if (used.contains(S)) {
      continue;
    }
    for (int C : mp[S]) {
      auto it = lower_bound(ss.begin(), ss.end(), C);
      if (it == ss.begin()) {
        continue;
      }
      int j = prev(it) - ss.begin();
      if (j <= i) {
        continue;
      }
      long long now = j - i;
      ans += now;
    }
    used.insert(S);
  }
  cout << ans << '\n';
  return 0;
}
