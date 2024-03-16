#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int N, H, W;
  cin >> N >> H >> W;
  vector<int> A(N), B(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n) >> B.at(n);
  }
  // xmin, yminを求める
  auto search_min = [&](vector<vector<bool> > &S) -> tuple<int, int> {
    int ymin = H;
    int xmin = W - 1;
    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        if (S[y][x] == true) {
          continue;
        }
        if (x < xmin) {
          xmin = x;
          ymin = y;
        } else if (x == xmin) {
          if (y < ymin) {
            xmin = x;
            ymin = y;
          }
        }
      }
    }
    return {ymin, xmin};
  };
  // 置く
  auto put = [&](vector<vector<bool> > &S, int y0, int x0, int h, int w) -> bool {
    for (int y = y0; y < y0 + h; y++) {
      assert(y < H);
      for (int x = x0; x < x0 + w; x++) {
        assert(x < W);
        if (S[y][x] == true) {  // 既に置かれていた
          return false;
        }
        S[y][x] = true;
      }
    }
    return true;
  };
  // 順列, 回転
  using T = tuple<vector<int>, vector<int> >;
  queue<T> q;
  q.push(make_tuple(vector<int>(), vector<int>(N, 0)));  // 初期値
  while (!q.empty()) {
    vector<int> perm = get<0>(q.front());
    vector<int> state = get<1>(q.front());
    q.pop();
    // 盤面構築
    vector<vector<bool> > S(H, vector<bool>(W, false));
    int x0 = 0;
    int y0 = 0;
    for (int i : perm) {
      assert(state[i] > 0);
      int h = A[i];
      int w = B[i];
      if (state[i] == 2) {
        swap(h, w);
      }
      // Sにiを置く
      bool now = put(S, y0, x0, h, w);
      assert(now == true);
      tie(y0, x0) = search_min(S);
    }
    
    for (int i = 0; i < N; i++) {  // (x0, y0)に置くタイル番号
      if (state[i] > 0) {  // 使用済み
        continue;
      }
      for (int k = 1; k <= 2; k++) {  // 回転するか
        int h = A[i];
        int w = B[i];
        if (k == 2) {
          swap(h, w);
        }
        // 置けるか確認
        if (x0 + w > W) {
          continue;
        }
        if (y0 + h > H) {
          continue;
        }
        // 置いてみる
        vector<vector<bool> > T(S);
        // Tにiを置く
        bool now = put(T, y0, x0, h, w);
        if (!now) {
          continue;
        }
        
        // 置けた
        auto [ny0, nx0] = search_min(T);
        if (nx0 == W - 1 && ny0 == H) {
          cout << "Yes" << endl;
          return 0;
        }
        vector<int> nperm(perm);
        nperm.push_back(i);
        vector<int> nstate(state);
        nstate[i] = k;
        q.push(make_tuple(nperm, nstate));
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
