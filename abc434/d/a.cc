#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
  int N;
  cin >> N;
  const int H = 2000;
  const int W = 2000;
  vector<vector<int> > board(H + 1, vector<int>(W + 1, -1));  // 雲iに唯一覆われていたらi
  vector<vector<int> > imos(H + 2, vector<int>(W + 2, 0));
  vector<tuple<int, int, int, int, int> > C(N);
  for (int i = 0; i < N; i++) {
    int U, D, L, R;
    cin >> U >> D >> L >> R;
    imos.at(U).at(L)++;
    imos.at(U).at(R + 1)--;
    imos.at(D + 1).at(L)--;
    imos.at(D + 1).at(R + 1)++;
    C.at(i) = make_tuple(D, R, U, L, i);
  }
  for (int y = 1; y <= H + 1; y++) {
    for (int x = 1; x <= W + 1; x++) {
      imos.at(y).at(x) += imos.at(y).at(x - 1);
    }
  }
  for (int x = 1; x <= W + 1; x++) {
    for (int y = 1; y <= H + 1; y++) {
      imos.at(y).at(x) += imos.at(y - 1).at(x);
    }
  }
  sort(C.begin(), C.end());

  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= W; x++) {
      if (imos.at(y).at(x) != 1) {
        continue;
      }
      // 唯一の雲に覆われている
      
      auto it = lower_bound(C.begin(), C.end(), make_tuple(y, x, -INF, -INF, -INF));
      while (true) {
        if (it == C.end()) {
          assert(false);
          exit(0);
        }
        auto [D, R, U, L, i] = *it;
        if (U <= y && y <= D && L <= x && x <= R) {
          board.at(y).at(x) = i;
          break;
        }
        it++;
      }
    }
  }

  // A=どれかの雲に覆われた個数
  int A = 0;
  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= W; x++) {
      if (imos.at(y).at(x) >= 1) {
        A++;
      }
    }
  }
  // B[i]: 雲iが唯一覆っている個数
  vector<int> B(N, 0);
  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= W; x++) {
      if (board.at(y).at(x) >= 0) {
        int i = board.at(y).at(x);
        B.at(i)++;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    int ans = H * W - A + B.at(i);
    cout << ans << '\n';
  }
  return 0;
}
