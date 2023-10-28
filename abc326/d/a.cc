#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string R, C;
  cin >> R >> C;
  vector<string> S(5);
  for (int n = 0; n < N; n++) {
    for (int m = 0; m < N - 3; m++) {
      S[n].push_back('.');
    }
    S[n].push_back('A');
    S[n].push_back('B');
    S[n].push_back('C');
    sort(S[n].begin(), S[n].end());
  }

  auto check_first = [&](int y) -> bool {
    if (y >= N) {
      return true;
    }
    for (int x = 0; x < N; x++) {
      if (S[y][x] == '.') {
        continue;
      }
      return (S[y][x] == R[y]);
    }
    assert(false);
    return true;
  };

  do {
    if (!check_first(4)) {
      continue;
    }
    do {
      if (!check_first(3)) {
        continue;
      }
      do {
        if (!check_first(2)) {
          continue;
        }
        do {
          if (!check_first(1)) {
            continue;
          }
          do {
            if (!check_first(0)) {
              continue;
            }
            // 縦にABCが1個ずつか確認
            auto checkABC= [&]() -> bool {
              for (int x = 0; x < N; x++) {
                int cntA = 0;
                int cntB = 0;
                int cntC = 0;
                for (int y = 0; y < N; y++) {
                  if (S[y][x] == 'A') {
                    if (cntA >= 1) {
                      return false;
                    }
                    cntA++;
                  } else if (S[y][x] == 'B') {
                    if (cntB >= 1) {
                      return false;
                    }
                    cntB++;
                  } else if (S[y][x] == 'C') {
                    if (cntC >= 1) {
                      return false;
                    }
                    cntC++;
                  }
                }
              }
              return true;
            };
            if (!checkABC()) {
              continue;
            }

            // Rの条件を満たすか
            auto checkR = [&]() -> bool {
              for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                  if (S[y][x] == '.') {
                    continue;
                  }
                  if (S[y][x] != R[y]) {
                    return false;
                  } else {
                    break;
                  }
                }
              }
              return true;
            };
            if (!checkR()) {
              continue;
            }
            // Cの条件を満たすか
            auto checkC = [&]() -> bool {
              for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                  if (S[y][x] == '.') {
                    continue;
                  }
                  if (S[y][x] != C[x]) {
                    return false;
                  } else {
                    break;
                  }
                }
              }
              return true;
            };
            if (!checkC()) {
              continue;
            }
            cout << "Yes" << endl;
            for (int y = 0; y < N; y++) {
              cout << S[y] << '\n';
            }
            return 0;
          } while (next_permutation(S[0].begin(), S[0].end()));
        } while (next_permutation(S[1].begin(), S[1].end()));
      } while (next_permutation(S[2].begin(), S[2].end()));
    } while (next_permutation(S[3].begin(), S[3].end()));
  } while (next_permutation(S[4].begin(), S[4].end()));
  cout << "No" << endl;
  return 0;
}
