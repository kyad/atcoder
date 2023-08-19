#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, const T b) { a = max(a, b); }

int main() {
  int N;
  cin >> N;
  vector<multiset<long long, greater<long long> > > st(N);
  for (int n = 0; n < N; n++) {
    int F;
    long long S;
    cin >> F >> S;
    F--;
    st.at(F).insert(S);
  }
  long long ans = -1;
  // 同じ
  for (int f = 0; f < N; f++) {
    if (st.at(f).size() <= 1) {
      continue;
    }
    multiset<long long>::iterator it = st.at(f).begin();
    long long now = *it;
    it++;
    now += ((*it) / 2);
    chmax(ans, now);
  }
  // 違うものから選ぶ
  vector<long long> v(N, -1);
  for (int f = 0; f < N; f++) {
    if (st[f].size() == 0) {
      continue;
    }
    v[f] = *st[f].begin();
  }
  sort(v.rbegin(), v.rend());
  if (v[1] >= 0) {
    long long now = v[0] + v[1];
    chmax(ans, now);
  }
  cout << ans << endl;
  return 0;
}
