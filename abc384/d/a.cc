#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long S;
  cin >> N >> S;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  long long sumA = 0;
  for (int i = 0; i < N; i++) {
    sumA += A.at(i);
  }
  S %= sumA;
  if (S == 0) {
    cout << "Yes" << endl;
    return 0;
  }

  // 尺取り法。[l, r)は半開区間とする
  int r = 0;
  long long sum = 0;
  for (int l = 0; l < N; l++) {
    // 条件を満たす最大のrを求める
    while (true) {
      int nr = r + 1;
      if (nr >= N * 2 + 1) {
        break;
      }
      if (nr >= l + N) {  // N個以上は取れない
        break;
      }
      // nrが条件を満たしているかチェック
      long long nsum = sum + A.at((nr + N - 1) % N);
      if (nsum > S) {
        break;
      }
      r = nr;
      // 条件にrを含める
      sum = nsum;
    }

    // この時点で[l, r)は条件を見たす最大の区間
    // 何かする。
    if (sum == S) {
      cout << "Yes" << endl;
      return 0;
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

  cout << "No" << endl;
  return 0;
}
