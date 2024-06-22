#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> HH(N);
  const int INF = 1e9 + 100;
  for (int i = 0; i < N; i++) {
    cin >> HH.at(i);
  }
  set<int> st;
  st.insert(INF);
  map<int, long long> count;  // count[h]: 高さhの個数
  long long sum = 0;
  vector<long long> ans;
  for (int i = 0; i < N; i++) {
    int H = HH.at(i);
    vector<int> del;
    long long now = 0;
    long long new_count = 1;
    for (int h : st) {
      if (H >= h) {
        del.push_back(h);
        new_count += count[h];
        now -= ((long long)h * (long long)count[h]);
      } else {
        break;
      }
    }
    // 掃き出す処理
    for (int d : del) {
      st.erase(d);
      count.erase(d);
    }
    st.insert(H);
    count[H] = new_count;
    now += ((long long)H * (long long)new_count);
    sum += now;
    ans.push_back(sum + 1);
  }
  dump(ans);
  return 0;
}
