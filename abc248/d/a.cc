#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  vector<set<int> > st(N + 1);
  for (int n = 1; n <= N; n++) {
    st[A.at(n)].insert(n);
  }
  vector<map<int, int> > mp(N + 1);
  for (int x = 1; x <= N; x++) {
    if (st[x].size() == 0) {
      continue;
    }
    int count = 1;
    for (set<int>::iterator it = st[x].begin(); it != st[x].end(); it++) {
      int idx = *it;
      mp[x][-idx] = count;
      count++;
    }
  }
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int L, R, X;
    cin >> L >> R >> X;
    if (mp[X].size() == 0) {
      cout << 0 << endl;
      continue;
    }
    int left, right;
    map<int, int>::iterator it;
    it = mp[X].lower_bound(-R);
    if (it == mp[X].end()) {
      right = 0;
    } else {
      right = it->second;
    }
    
    it = mp[X].lower_bound(-L + 1);
    if (it == mp[X].end()) {
      left = 0;
    } else {
      left = it->second;
    }
    int ans = right - left;
    cout << ans << endl;
  }
  return 0;
}
