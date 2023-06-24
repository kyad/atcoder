#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<string> norm(vector<string> S) {
  int H = S.size();
  int W = S.at(0).size();
  const int INF = 1e9;
  int y0 = INF, y1 = -INF;
  int x0 = INF, x1 = -INF;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S[y][x] == '#') {
        y0 = min(y0, y);
        y1 = max(y1, y);
        x0 = min(x0, x);
        x1 = max(x1, x);
      }
    }
  }
  vector<string> T;
  for (int y = y0; y <= y1; y++) {
    string now;
    for (int x = x0; x <= x1; x++) {
      now.push_back(S[y][x]);
    }
    T.push_back(now);
  }
  return T;
}

int main() {
  int _HA, _WA;
  cin >> _HA >> _WA;
  vector<string> _A(_HA);
  for (int y = 0; y < _HA; y++) {
    cin >> _A.at(y);
  }
  int _HB, _WB;
  cin >> _HB >> _WB;
  vector<string> _B(_HB);
  for (int y = 0; y < _HB; y++) {
    cin >> _B.at(y);
  }
  int _HX, _WX;
  cin >> _HX >> _WX;
  vector<string> _X(_HX);
  for (int y = 0; y < _HX; y++) {
    cin >> _X.at(y);
  }
  vector<string> A = norm(_A);
  int HA = A.size();
  int WA = A.at(0).size();
  vector<string> B = norm(_B);
  int HB = B.size();
  int WB = B.at(0).size();
  vector<string> X = norm(_X);
  int HX = X.size();
  int WX = X.at(0).size();
  for (int ya = 0; HA + ya <= HX; ya++) {
    for (int xa = 0; WA + xa <= WX; xa++) {
      for (int yb = 0; HB + yb <= HX; yb++) {
        for (int xb = 0; WB + xb <= WX; xb++) {
          vector<string> C;
          for (int y = 0; y < HX; y++) {
            string now(WX, '.');
            C.push_back(now);
          }
          // Copy A --> C
          for (int i = 0; i < HA; i++) {
            for (int j = 0; j < WA; j++) {
              if (A[i][j] == '.') {
                continue;
              }
              int y = i + ya;
              int x = j + xa;
              assert(0 <= y && y < HX);
              assert(0 <= x && x < WX);
              C[y][x] = '#';
            }
          }
          // Copy B --> C
          for (int i = 0; i < HB; i++) {
            for (int j = 0; j < WB; j++) {
              if (B[i][j] == '.') {
                continue;
              }
              int y = i + yb;
              int x = j + xb;
              assert(0 <= y && y < HX);
              assert(0 <= x && x < WX);
              C[y][x] = '#';
            }
          }
          // Check
          if (C == X) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
