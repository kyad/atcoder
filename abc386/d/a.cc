#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int INF = 1e9+2;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int> > bs_xy;
  vector<pair<int, int> > ws;
  for (int j = 0; j < M; j++) {
    int y, x;
    char C;
    cin >> y >> x >> C;
    y--; x--;
    if (C == 'B') {
      bs_xy.push_back(make_pair(x, y));
    } else {
      ws.push_back(make_pair(y, x));
    }
  }
  // Bのyを上書きする
  sort(bs_xy.begin(), bs_xy.end());
  int B = bs_xy.size();
  int ymax = -1;
  for (int i = B - 1; i >= 0; i--) {
    int y = bs_xy[i].second;
    ymax = max(ymax, y);
    bs_xy[i].second = ymax;
  }
  vector<pair<int, int> > bs(B);  // yx順
  for (int i = 0; i < B; i++) {
    bs.at(i) = make_pair(bs_xy.at(i).second, bs_xy.at(i).first);
  }
  // wsの条件を見たしているかチェック
  map<int, int> mp;
  for (auto [by, bx]: bs) {
    mp[bx] = by;
  }
  for (auto [wy, wx] : ws) {
    auto it = mp.lower_bound(wx);
    if (it == mp.end()) {
      continue;
    }
    int by = it->second;
    if (by >= wy) {  // NG
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
  return 0;
}
