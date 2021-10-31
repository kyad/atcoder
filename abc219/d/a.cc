// https://atcoder.jp/contests/abc219/tasks/abc219_d

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int encode(int x, int y) {
  return x * 1000 + y;
}
// decode:
// x = value / 1000
// y = value % 1000

int main() {
  int N;
  cin >> N;
  int X, Y;
  cin >> X >> Y;
  vector<int> A(N), B(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n) >> B.at(n);
  }
  unordered_map<int, int> dp;
  dp[encode(0, 0)] = 0;
  for (int n = 0; n < N; n++) {
    vector<int> x;
    vector<int> y;
    vector<int> num;
    for (unordered_map<int, int>::iterator it = dp.begin(); it != dp.end(); it++) {
      int value = it->first;
      x.push_back(value / 1000);
      y.push_back(value % 1000);
      num.push_back(it->second);
    }
    for (size_t i = 0; i < x.size(); i++) {
      // たこやきX個以上の状態はX個に丸める
      // たいやきY個以上の状態はY個に丸める
      int nx = min(x[i] + A[n], X);
      int ny = min(y[i] + B[n], Y);
      if (dp.count(encode(nx, ny)) > 0) {
        dp[encode(nx, ny)] = min(dp[encode(nx, ny)], num[i] + 1);
      } else {
        dp[encode(nx, ny)] = num[i] + 1;
      }
    }
  }
  int ans = -1;
  for (unordered_map<int, int>::iterator it = dp.begin(); it != dp.end(); it++) {
    int value = it->first;
    int x = value / 1000;
    int y = value % 1000;
    if (x >= X && y >= Y) {
      if (ans < 0) {
        ans = it->second;
      } else {
        ans = min(ans, it->second);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
