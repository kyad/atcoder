#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/** stringの配列用のデバッグ用関数 */
ostream& operator<<(ostream& os, const vector<string> &v) {
  int y0 = 0;
  int y1 = (int)v.size() - 1;
  for (int i = y0; i <= y1; i++) {
    os << '\n'<<v[i];
  }
  return os;
}

/**
 * Sのうち、emptyでない余白を除いて返す
 * 計算量: O(HW)
 */
vector<string> normalize(vector<string> const& S, char empty = '.') {
  int H = S.size();
  if (H == 0) {
    vector<string> ans(0);
    return ans;
  }
  int W = S[0].size();
  // emptyでない最大・最小のxを見つける
  int miny = H;
  int maxy = -1;
  int minx = W;
  int maxx = -1;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S[y][x] != empty) {
        miny = min(miny, y);
        maxy = max(maxy, y);
        minx = min(minx, x);
        maxx = max(maxx, x);
      }
    }
  }
  int nh = 0;
  int nw = 0;
  if (miny < H) {
    nh = maxy - miny + 1;
    nw = maxx - minx + 1;
  }
  vector<string> ans(nh, string(nw, '_'));
  for (int y = 0; y < nh; y++) {
    for (int x = 0; x < nw; x++) {
      ans.at(y).at(x) = S.at(miny + y).at(minx + x);
    }
  }
  return ans;
}

/**
 * Sを反時計回りに回転する
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
      int nx = y;
      int ny = W - 1 - x;
      ans.at(ny).at(nx) = S.at(y).at(x);
    }
  }
  return ans;
}

/**
 * SをH*Wに拡大し、足りない所はemptyで埋める
 * 計算量: O(HW)
 */
vector<string> extend(vector<string> const& S, int H, int W, char empty = '.') {
  vector<string> ans(H, string(W, empty));
  int ph = S.size();
  if (ph == 0) {
    return ans;
  }
  int pw = S[0].size();
  for (int y = 0; y < ph; y++) {
    for (int x = 0; x < pw; x++) {
      ans.at(y).at(x) = S.at(y).at(x);
    }
  }
  return ans;
}

const int N = 3;  // ポリオミノの数
const int M = 4;  // 敷き詰める枠のサイズ

bool check(vector<vector<string> > Q, int dy0, int dx0, int dy1, int dx1, int dy2, int dx2) {
  vector<string> R(Q[0]);
  for (int y = 0; y < M; y++) {
    for (int x = 0; x < M; x++) {
      R[y][x] = '.';
    }
  }
  for (int i = 0; i < N; i++) {
    int sx, sy;
    if (i == 0) {
      sx = dx0; sy = dy0;
    } else if (i == 1) {
      sx = dx1; sy = dy1;
    } else {
      sx = dx2; sy = dy2;
    }
    for (int y = 0; y < M; y++) {
      for (int x = 0; x < M; x++) {
        if (Q[i][y][x] == '#') {
          int ny = y + sy;
          int nx = x + sx;
          if (ny >= M || nx >= M) {
            return false;
          }
          if (R[ny][nx] == '#') {
            return false;
          }
          R[ny][nx] = '#';
        }
      }
    }
  }
  // Check all are '#'
  for (int y = 0; y < M; y++) {
    for (int x = 0; x < M; x++) {
      if (R[y][x] == '.') {
        return false;
      }
    }
  }
  return true;
}

int main() {
  vector<vector<string> > _P(N, vector<string>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> _P[i][j];
    }
  }
  vector<vector<string> > P(N);
  for (int i = 0; i < N; i++) {
    P[i] = normalize(_P[i]);
  }
  //R[i][k]: P[i]をk回回転したもの
  vector<vector<vector<string> > > R(N, vector<vector<string> >(4));
  for (int i = 0; i < N; i++) {
    R[i][0] = extend(P[i], M, M);
    for (int k = 1; k <= 3; k++) {
      R[i][k] = extend(normalize(rotate(R[i][k-1])), M, M);
    }
  }
  vector<vector<string> > Q(N);
  // 回転
  for (int k0 = 0; k0 <= 3; k0++) {
    Q[0] = R[0][k0];
    for (int k1 = 0; k1 <= 3; k1++) {
      Q[1] = R[1][k1];
      for (int k2 = 0; k2 <= 3; k2++) {
        Q[2] = R[2][k2];
        // シフト
        for (int dy0 = 0; dy0 < M; dy0++) {
          for (int dx0 = 0; dx0 < M; dx0++) {
            for (int dy1 = 0; dy1 < M; dy1++) {
              for (int dx1 = 0; dx1 < M; dx1++) {
                for (int dy2 = 0; dy2 < M; dy2++) {
                  for (int dx2 = 0; dx2 < M; dx2++) {
                    bool now = check(Q, dy0, dx0, dy1, dx1, dy2, dx2);
                    if (now) {
                      cout << "Yes" << endl;
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
