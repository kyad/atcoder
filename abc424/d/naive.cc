#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int dist(const vector<string> &S, const vector<string> &T) {
  int H = S.size();
  int W = S.at(0).size();
  assert((int)T.size() == H);
  assert((int)T.at(0).size() == W);
  int ans = 0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S.at(y).at(x) != T.at(y).at(x)) {
        ans++;
      }
    }
  }
  return ans;
}

int naive(const vector<string> &S) {
  int H = S.size();
  int W = S.at(0).size();
  int M = H * W;
  int M2 = 1 << M;
  int ans = INF;
  for (int m = 0; m < M2; m++) {
    vector<string> T;
    for (int y = 0; y < H; y++) {
      string line;
      for (int x = 0; x < W; x++) {
        if (m>>(y * W + x)&1) {
          line.push_back('#');
        } else {
          line.push_back('.');
        }
      }
      T.push_back(line);
    }
    // check
    bool ok = true;
    for (int y = 0; y <= H - 2; y++) {
      for (int x = 0; x <= W - 2; x++) {
        if (T.at(y).at(x) == '.' || T.at(y + 1).at(x) == '.' || T.at(y).at(x + 1) == '.' || T.at(y + 1).at(x + 1) == '.') {
          // ok
        } else {
          ok = false;
        }
      }
    }
    if (ok) {
      int now = dist(S, T);
      ans = min(ans, now);
    }
  }
  return ans;
}

int solve() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  int ans = naive(S);
  cout << ans << '\n';
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    solve();
  }
  return 0;
}
