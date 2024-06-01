#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int> > A(M);
  vector<char> R(M);
  for (int m = 0; m < M; m++) {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
      int a;
      cin >> a;
      a--;
      A.at(m).push_back(a);
    }
    cin >> R.at(m);
  }
  int N2 = 1<<N;
  int ans = 0;

  auto check = [&](int s) -> bool {  // s=1: 正しい鍵
    // M個の条件を満たすかチェック
    for (int m = 0; m < M; m++) {
      int C = A.at(m).size();
      int correct = 0;  // 正しい鍵の個数
      for (int c = 0; c < C; c++) {
        int a = A.at(m).at(c);
        int b = (s>>a)&1;
        if (b == 1) {  // a正しい鍵
          correct++;
        }
      }
      if (correct >= K) {
        // 開く時
        if (R.at(m) == 'x') {  // 矛盾
          return false;
        }
      } else {
        // 開かない時
        if (R.at(m) == 'o') {  // 矛盾
          return false;
        }
      }
    }
    return true;
  };


  for (int s = 0; s < N2; s++) {
    if (check(s)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
