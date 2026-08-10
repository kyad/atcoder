#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
  int N, Q;
  cin >> N >> Q;
  map<string, vector<int>> is;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    if (is.contains(S)) {
      is[S].push_back(i);
    } else {
      is[S].push_back(-1);
      is[S].push_back(i);
    }
  }
  for (auto [S, v] : is) {
    v.push_back(INF);
  }
  for (int qi = 0; qi < Q; qi++) {
    int L, R;
    string T;
    cin >> L >> R >> T;
    L--; R--;
    if (!is.contains(T)) {
      cout << 0 << '\n';
      continue;
    }
    int ans = prev(upper_bound(is[T].begin(), is[T].end(), R)) - lower_bound(is[T].begin(), is[T].end(), L) + 1;
    cout << ans << '\n';
  }
  return 0;
}
