#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/**
 * Sを時計回りに回転する
 * 計算量: O(HW)
 */
vector<string> rotate(vector<string> const& S) {
  int H = S.size();
  if (H == 0) {
    vector<string> ans(0);
    return ans;
  }
  int W = S[0].size();
  vector<string> ans(W, string(H, '_'));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      int nx = H - 1 - y;
      int ny = x;
      ans.at(ny).at(nx) = S.at(y).at(x);
    }
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int y = 0; y < N; y++) {
    cin >> S.at(y);
  }
  vector<string> T(N);
  for (int y = 0; y < N; y++) {
    cin >> T.at(y);
  }
  auto f = [&]() {
    int ans = 0;
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        if (S.at(y).at(x) != T.at(y).at(x)) {
          ans++;
        }
      }
    }
    return ans;
  };
  const int INF = 1e9;
  int ans = INF;
  for (int i = 0; i < 4; i++) {
    int now = f() + i;
    ans = min(now, ans);
    S = rotate(S);
  }
  cout << ans << endl;
  return 0;
}
