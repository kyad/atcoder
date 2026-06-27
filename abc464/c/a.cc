#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N), D(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> D.at(i) >> B.at(i);
  }
  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    mp[A.at(i)]++;
  }
  vector<vector<pair<int, int>>> events(M + 1);
  for (int i = 0; i < N; i++) {
    events.at(D.at(i)).push_back(make_pair(i, B.at(i)));
  }
  for (int j = 1; j <= M; j++) {
    for (auto [i, b] : events.at(j)) {
      int a = A.at(i);
      assert(mp.contains(a));
      mp[a]--;
      if (mp[a] == 0) {
        mp.erase(a);
      }
      mp[b]++;
    }
    int ans = mp.size();
    cout << ans << '\n';
  }
  return 0;
}
