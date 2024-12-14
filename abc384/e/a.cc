#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

using lll = __int128;

int main() {
  int H, W;
  long long X;
  cin >> H >> W >> X;
  int P, Q;
  cin >> P >> Q;
  P--; Q--;
  vector<vector<long long> > S(H, vector<long long>(W));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> S.at(y).at(x);
    }
  }
  vector<vector<bool> > seen(H, vector<bool>(W, false));
  set<pair<long long, pair<int, int> > > st;
  st.insert(make_pair(S.at(P).at(Q), make_pair(P, Q)));
  seen.at(P).at(Q) = true;
  int dy[4] = {0, +1, 0, -1};
  int dx[4] = {+1, 0, -1, 0};
  long long strength = 0;  // 高橋くんの強さ
  while (!st.empty()) {
    long long s = st.begin()->first;  // 最初の強さ
    int y = st.begin()->second.first;
    int x = st.begin()->second.second;
    lll lhs = (lll)X * (lll)s;
    lll rhs = (lll)strength;
    if (strength == 0 || lhs < rhs) {
      strength += s;
      st.erase(st.begin());
      for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || ny >= H || nx < 0 || nx >= W || seen.at(ny).at(nx) == true) {
          continue;
        }
        long long ns = S.at(ny).at(nx);
        st.insert(make_pair(ns, make_pair(ny, nx)));
        seen.at(ny).at(nx) = true;
      }
    } else {
      break;
    }
  }
  long long ans = strength;
  cout << ans << endl;
  return 0;
}

