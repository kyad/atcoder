#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  long long M;
  cin >> N >> K >> M;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  long long ans = 0;
  long long sum = 0;
  int r = 0;
  for (int l = 0; l < N; l++) {
    // 条件を満たす最大のrを求める
    while (true) {
      if (sum >= M && (r - l >= K)) {
        break;
      }
      int nr = r + 1;
      if (nr >= N + 1) {
        break;
      }
      r = nr;
      sum += A.at(r - 1);
    }

    if (sum >= M && (r - l >= K)) {
      ans += (N - r + 1);
    }

    // lをインクリメントする前の処理
    if (l == r) {
      // このとき、[l, r)は空集合なので、条件からlを除外する処理は不要
      r++;  // 先にrをインクリメントする
    } else {
      // 条件からlを除外する
      sum -= A.at(l);
    }
  }

  cout << ans << '\n';
  return 0;
}
