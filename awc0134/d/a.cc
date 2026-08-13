#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int> H(N);
  vector<long long> V(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i) >> V.at(i);
  }
  vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(N, vector<long long>(M + 1, 0)));
  for (int i = 0; i < N; i++) {
    dp.at(i).at(i).at(H.at(i)) = V.at(i);
  }
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      for (int k = 0; k <= M; k++) {
        if (i - 1 > 0) {
          chmax(dp.at(i - 1).at(j).at(k), dp.at(i).at(j).at(k));
          if (k - H.at(i - 1) >= 0) {
            chmax(dp.at(i - 1).at(j).at(k), dp.at(i).at(j).at(k - H.at(i - 1)) + V.at(i - 1));
          }
        }
        if (j + 1 < N) {
          chmax(dp.at(i).at(j + 1).at(k), dp.at(i).at(j).at(k));
          if (k - H.at(j + 1) >= 0) {
            chmax(dp.at(i).at(j + 1).at(k), dp.at(i).at(j).at(k - H.at(j + 1)) + V.at(j + 1));
          }
        }
      }
    }
  }
  for (int qi = 0; qi < Q; qi++) {
    int L, R, X;
    cin >> L >> R >> X;
    L--; R--;
    long long ans = 0;
    for (int k = 0; k <= X; k++) {
      chmax(ans, dp.at(L).at(R).at(k));
    }
    cout << ans << '\n';
  }
  return 0;
}
