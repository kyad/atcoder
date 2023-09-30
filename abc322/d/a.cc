#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N = 3;
int M = 4;

// 2d-matrix
ostream& operator<<(ostream& os, const vector<string > &v) {
  int y0 = 0;
  int y1 = (int)v.size() - 1;
  for (int i = y0; i <= y1; i++) {
    os << '\n'<<v[i];
  }
  return os;
}

vector<string> normalize(vector<string> P) {
  int miny = M;
  int minx = M;
  for (int x = 0; x < M; x++) {
    bool found = false;
    for (int y = 0; y < M; y++) {
      if (P[y][x] == '#') {
        found = true;
        break;
      }
    }
    if (found) {
      minx = x;
      break;
    }
  }
  for (int y = 0; y < M; y++ ){
    bool found = false;
    for (int x = 0; x < M; x++) {
      if (P[y][x] == '#') {
        found = true;
        break;
      }
    }
    if (found) {
      miny = y;
      break;
    }
  }
  // No '#'
  if (minx == M) {
    minx = 0;
  }
  if (miny == M) {
    miny = 0;
  }
  vector<string> ans(P);
  for (int y = 0; y < M; y++) {
    for (int x = 0; x < M; x++) {
      ans[y][x] = '.';
    }
  }
  for (int y = miny; y < M; y++) {
    for (int x = minx; x < M; x++) {
      ans[y - miny][x - minx] = P[y][x];
    }
  }
  return ans;
}

vector<string> rotate(vector<string> P) {
  vector<string> ans(P);
  for (int y = 0; y < M; y++) {
    for (int x = 0; x < M; x++) {
      int ny = M - 1 - x;
      int nx = y;
      ans[ny][nx] = P[y][x];
    }
  }
  return ans;
}

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
  //R[i][k]: R[i]をk回回転したもの
  vector<vector<vector<string> > > R(N, vector<vector<string> >(4));
  for (int i = 0; i < N; i++) {
    R[i][0] = P[i];
    for (int k = 1; k <= 3; k++) {
      R[i][k] = normalize(rotate(R[i][k-1]));
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
