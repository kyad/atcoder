// https://atcoder.jp/contests/abc219/tasks/abc219_f

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  long long K;
  cin >> K;
  set<pair<long long, long long> > st;
  long long dx = 0;
  long long dy = 0;
  st.insert(make_pair(dx, dy));
  for (size_t i = 0; i < S.size(); i++) {
    switch (S[i]) {
    case 'L': dx--; break;
    case 'R': dx++; break;
    case 'U': dy++; break;
    case 'D': dy--; break;
    }
    st.insert(make_pair(dx, dy));
  }
  if (dx == 0 && dy == 0) {
    cout << st.size() << endl;
    return 0;
  }

  // Normalize to dx > 0
  if (dx == 0) {
    set<pair<long long, long long> > now;
    for (set<pair<long long, long long> >::iterator it = st.begin(); it != st.end(); it++) {
      now.insert(make_pair(it->second, it->first));
    }
    st = now;
    swap(dx, dy);
  }
  assert(dx != 0);
  if (dx < 0) {
    set<pair<long long, long long> > now;
    for (set<pair<long long, long long> >::iterator it = st.begin(); it != st.end(); it++) {
      now.insert(make_pair(-it->first, it->second));
    }
    st = now;
    dx *= -1;
  }
  assert(dx > 0);

  // Normalize to dy >= 0
  if (dy < 0) {
    set<pair<long long, long long> > now;
    for (set<pair<long long, long long> >::iterator it = st.begin(); it != st.end(); it++) {
      now.insert(make_pair(it->first, -it->second));
    }
    st = now;
    dy *= -1;
  }
  assert(dy >= 0);

  // Shift to x >= 0 for all points
  {
    set<pair<long long, long long> > now;
    for (set<pair<long long, long long> >::iterator it = st.begin(); it != st.end(); it++) {
      now.insert(make_pair(it->first + S.size(), it->second));
    }
    st = now;
  }

  // Normalize to x = nx + k * dx, 0 <= nx < dx
  map<pair<long, long>, set<long long> > mp;
  for (set<pair<long long, long long> >::iterator it = st.begin(); it != st.end(); it++) {
    long long x = it->first;
    long long y = it->second;
    long long k;
    assert(x >= 0);
    k = x / dx;
    long long nx = x - k * dx;
    long long ny = y - k * dy;
    assert(0 <= nx && nx < dx);
    mp[make_pair(nx, ny)].insert(k);
  }

  long long ans = 0;
  for (map<pair<long, long>, set<long long> >::iterator it = mp.begin(); it != mp.end(); it++) {
    set<long long> st = it->second;
    vector<long long> v;
    for (set<long long>::iterator j = st.begin(); j != st.end(); j++) {
      v.push_back(*j);
    }
    for (size_t i = 0; i < v.size(); i++) {
      long long now = K;
      if (i + 1 < v.size()) {
        now = min(now, v[i + 1] - v[i]);
      }
      ans += now;
    }
  }
  cout << ans << endl;
  return 0;
}
