// https://atcoder.jp/contests/abc236/tasks/abc236_f

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int M = (1 << N) - 1;
  vector<pair<int, int> > C;
  for (int m = 1; m <= M; m++) {
    int c;
    cin >> c;
    C.push_back(make_pair(c, m));
  }
  sort(C.begin(), C.end());
  set<int> st;
  long long ans = 0;
  for (size_t i = 0; i < C.size(); i++) {
    int c = C[i].first;
    int m = C[i].second;
    if (st.count(m) > 0) {
      continue;
    }
    ans += c;
    vector<int> v;
    v.push_back(m);
    for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
      v.push_back(*it ^ m);
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
      st.insert(*it);
    }
  }
  cout << ans << endl;
  return 0;
}
