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
  auto search_min = [&](vector<vector<bool> > &S, int &xmin, int &ymin) {
    xmin = W - 1;
    ymin = H;
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
      for (int y = y0; y < y0 + h; y++) {
        assert(y < H);
        for (int x = x0; x < x0 + w; x++) {
          assert(x < W);
          assert(S[y][x] == false);
          S[y][x] = true;
        }
      }
      search_min(S, x0, y0);
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
        bool skip = false;
        for (int y = y0; y < y0 + h; y++) {
          assert(y < H);
          for (int x = x0; x < x0 + w; x++) {
            assert(x < W);
            if (T[y][x] == true) {  // 既に置かれていた
              skip = true;
              break;
            }
            T[y][x] = true;
          }
          if (skip) {
            break;
          }
        }
        if (skip) {
          continue;
        }
        // 置けた
        int ny0 = -1, nx0 = -1;
        search_min(T, nx0, ny0);
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
