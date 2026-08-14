#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<long long>> A(N, vector<long long>(M));
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> A.at(y).at(x);
    }
  }
  vector<vector<long long>> dp(N, vector<long long>(M, 0));
  dp.at(0).at(0) = A.at(0).at(0);
  const int dy[4] = {0, +1};
  const int dx[4] = {+1, 0};
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      for (int k = 0; k < 2; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
          continue;
        }
        chmax(dp.at(ny).at(nx), dp.at(y).at(x) + A.at(ny).at(nx));
      }
    }
  }
  long long ans = dp.at(N - 1).at(M - 1);
  cout << ans << '\n';
  return 0;
}
