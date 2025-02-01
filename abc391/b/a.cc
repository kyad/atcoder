#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int y = 0; y < N; y++) {
    cin >> S.at(y);
  }
  vector<string> T(M);
  for (int y = 0; y < M; y++) {
    cin >> T.at(y);
  }
  for (int ys = 0; ys + M <= N; ys++) {  // a
    for (int xs = 0; xs + M <= N; xs++) {  // b
      // チェック
      bool ok = true;
      for (int y = 0; y < M; y++) {
        for (int x = 0; x < M; x++) {
          if (S.at(ys + y).at(xs + x) != T.at(y).at(x)) {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        cout << (ys + 1) << ' ' << (xs + 1) << endl;
        return 0;
      }
    }
  }
  assert(false);
  return 0;
}
