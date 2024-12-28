#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int f(const vector<int>& A, int N) {
  assert(A.size() % 2 == 0);
  int M = A.size() / 2;
  vector<int> B(M);
  for (int j = 0; j < M; j++) {
    if (A.at(j * 2) == A.at(j * 2 + 1)) {
      B.at(j) = A.at(j * 2);
    } else {
      B.at(j) = -1;  // x
    }
  }
  vector<int> count(N + 1, 0);  // count[a]: aの個数
  int count_sum = 0;  // countの和
  // 尺取り法。[l, r)は半開区間とする
  int r = 0;
  int ans = 0;
  for (int l = 0; l < M; l++) {
    // 条件を満たす最大のrを求める
    while (true) {
      int nr = r + 1;
      if (nr >= M + 1) {
        break;
      }
      // nrが条件を満たしているかチェック
      if (B.at(nr - 1) == -1) {
        break;
      }
      if (count.at(B.at(nr - 1)) > 0) {
        break;
      }
      r = nr;
      // 条件にrを含める
      count.at(B.at(nr - 1))++;
      count_sum++;
    }

    // この時点で[l, r)は条件を見たす最大の区間
    // 何かする。
    ans = max(ans, count_sum);

    // lをインクリメントする前の処理
    if (l == r) {
      // このとき、[l, r)は空集合なので、条件からlを除外する処理は不要
      r++;  // 先にrをインクリメントする
    } else {
      // 条件からlを除外する
      if (B.at(l) != -1) {
        count.at(B.at(l))--;
        count_sum--;
      }
    }
  }
  ans *= 2;
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<int> A0;  // 偶数スタート
  for (int i = 0; i + 1 <= N - 1; i += 2) {
    A0.push_back(A.at(i));
    A0.push_back(A.at(i + 1));
  }
  vector<int> A1;  // 奇数スタート
  for (int i = 1; i + 1 <= N - 1; i += 2) {
    A1.push_back(A.at(i));
    A1.push_back(A.at(i + 1));
  }
  int ans0 = f(A0, N);
  int ans1 = f(A1, N);
  int ans = max(ans0, ans1);
  cout << ans << endl;
  return 0;
}
