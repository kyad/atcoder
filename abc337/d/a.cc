#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  const int INF = 1e9;
  auto f = [&](const vector<char> &A) {
    int N = A.size();
    int os = 0;
    int xs = 0;
    int ans = INF;
    // 尺取り法。[l, r)は半開区間とする
    for (int l = 0; l + K <= N; l++) {
      int r = l + K;
      if (l == 0) {
        // 初期値
        for (int i = l; i < r; i++) {
          if (A.at(i) == 'o') {
            os++;
          } else if (A.at(i) == 'x') {
            xs++;
          }
        }
      } else {
        if (A.at(r - 1) == 'o') {
          os++;
        } else if (A.at(r - 1) == 'x') {
          xs++;
        }
      }
      
      if (xs == 0) {  // OK
        int now = K - os;
        ans = min(ans, now);
      }

      // leftをインクリメントする前の処理
      // 条件からleftを除外する
      if (A.at(l) == 'o') {
        os--;
      } else if (A.at(l) == 'x') {
        xs--;
      }
    }
    return ans;
  };
  int ans = INF;
  // 横
  for (int y = 0; y < H; y++) {
    vector<char> A;
    for (int x = 0; x < W; x++) {
      A.push_back(S[y][x]);
    }
    int now = f(A);
    ans = min(ans, now);
  }
  // 縦
  for (int x = 0; x < W; x++) {
    vector<char> A;
    for (int y = 0; y < H; y++) {
      A.push_back(S[y][x]);
    }
    int now = f(A);
    ans = min(ans, now);
  }
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
