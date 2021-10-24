// https://atcoder.jp/contests/abc224/tasks/abc224_e

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> R(N), C(N);
  map<int, vector<int> > mp;
  for (int n = 0; n < N; n++) {
    int r, c, a;
    cin >> r >> c >> a;
    R.at(n) = r;
    C.at(n) = c;
    mp[a].push_back(n);
  }
  unordered_map<int, int> row_max, col_max;
  vector<int> ans(N);
  for (map<int, vector<int> >::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++) {
    for (size_t i = 0; i < it->second.size(); i++) {
      int n = it->second[i];
      int r = row_max.count(R[n]) ? (row_max[R[n]] + 1) : 0;
      int c = col_max.count(C[n]) ? (col_max[C[n]] + 1) : 0;
      ans[n] = max(r, c);
    }
    for (size_t i = 0; i < it->second.size(); i++) {
      int n = it->second[i];
      row_max[R[n]] = max(row_max[R[n]], ans[n]);
      col_max[C[n]] = max(col_max[C[n]], ans[n]);
    }
  }
  for (int n = 0; n < N; n++) {
    cout << ans[n] << endl;
  }
  return 0;
}
