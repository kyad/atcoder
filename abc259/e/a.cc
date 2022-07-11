// https://atcoder.jp/contests/abc259/tasks/abc259_e

#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<int, multiset<int> > mp; // mp[p]はpに対応するeのうち大きいもの高々2つを重複を許して持つ
  vector<vector<int> > P(N), E(N);
  for (int n = 0; n < N; n++) {
    int M;
    cin >> M;
    for (int m = 0; m < M; m++) {
      int p, e;
      cin >> p >> e;
      P.at(n).push_back(p);
      E.at(n).push_back(e);
      mp[p].insert(e);
      if (mp[p].size() == 3) {
        mp[p].erase(mp[p].begin());
      }
    }
  }

  set<set<int> > st;
  for (int n = 0; n < N; n++) {
    set<int> a;  // n個目以外の値のLCM。各p^eのうち最大のeでないp^eを因数に持つ時に、aはpを要素に持つ
    for (size_t i = 0; i < P.at(n).size(); i++) {
      int p = P.at(n).at(i);
      int e = E.at(n).at(i);
      if (e == (*mp[p].rbegin())) {  // Equals to max
        if (mp[p].size() == 2 && e == (*mp[p].begin())) {  // 1位と2位が同じeの時はOK
          continue;
        }
        a.insert(p);
      }
    }
    st.insert(a);
  }
  cout << st.size() << endl;
  return 0;
}
