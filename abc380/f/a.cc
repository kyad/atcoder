#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, L;
  cin >> N >> M >> L;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<int> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B.at(i);
  }
  vector<int> C(L);
  for (int i = 0; i < L; i++) {
    cin >> C.at(i);
  }

  int K = N + M + L;
  int K3 = 1;
  for (int i = 0; i < K; i++) K3 *= 3;
  vector<int> X(K);  // X[k]: k枚目の場所。0=場、1=高橋君、2=青木君
  vector<int> D(K);  // k枚目に書いてある数字
  for (int n = 0; n < N; n++) {  // 高橋君
    X.at(n) = 1;
    D.at(n) = A.at(n);
  }
  for (int m = 0; m < M; m++) {  // 青木君
    X.at(N + m) = 2;
    D.at(N + m) = B.at(m);
  }
  for (int l = 0; l < L; l++) {  // 場
    X.at(N + M + l) = 0;
    D.at(N + M + l) = C.at(l);
  }

  auto encode = [&](const vector<int>& X) -> int {
    int s = 0;
    for (int k = K - 1; k >= 0; k--) {
      s *= 3;
      s += X.at(k);
    }
    return s;
  };
  auto decode = [&](int s) -> vector<int> {
    vector<int> X(K);
    for (int k = 0; k < K; k++) {
      X.at(k) = s % 3;
      s /= 3;
    }
    return X;
  };

  // 状態sの時、人pが必勝か。
  // p=1:高橋君、p=2:青木君
  vector<vector<int> > memo(K3, vector<int>(3, -1));
  auto f = [&](auto f, int s, int p) -> int {
    if (memo[s][p] >= 0) {
      return memo[s][p];
    }
    // 遷移先の状態を列挙する
    vector<int> ts;  // 遷移先
    vector<int> X = decode(s);
    for (int k = 0; k < K; k++) {  // 捨てる
      if (X.at(k) != p) {
        continue;
      }
      X.at(k) = 0;  // 場に移動
      ts.push_back(encode(X));
      for (int l = 0; l < K; l++) {  // 取る
        if (X.at(l) == 0 && D.at(l) < D.at(k)) {  // 場にあって、かつ数字が小さい時
          X.at(l) = p;  // pに移動
          ts.push_back(encode(X));
          X.at(l) = 0;  // コピー削減のため戻す
        }
      }
      X.at(k) = p;  // コピー削減のため戻す
    }
    // 必勝かどうかを調べる
    int ans = 0;
    for (int t : ts) {
      if (f(f, t, 3 - p) == 0) {
        ans = 1;
        break;
      }
    }
    return memo[s][p] = ans;
  };

  int ans = f(f, encode(X), 1);
  if (ans == 1) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }
  return 0;
}
