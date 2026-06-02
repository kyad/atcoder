#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K, M;
  long long X;
  cin >> N >> K >> M >> X;
  vector<long long> Y(M);
  for (int j = 0; j < M; j++) {
    cin >> Y.at(j);
  }
  K = min(K, N);
  vector<int> b(N);
  for (int i = 0; i < N; i++) {
    b.at(i) = (X >> i) & 1;
  }
  auto rotate = [&](vector<int> &b) -> vector<int> {
    vector<int> ans;
    for (int i = 1; i < N; i++) {
      ans.push_back(b.at(i));
    }
    ans.push_back(1);
    return ans;
  };
  // 高橋君の操作
  while (K > 0) {
    if (b.at(0) == 1) {
      break;
    }
    b = rotate(b);
    K--;
  }
  // 青木君の操作
  vector<vector<int>> e(M, vector<int>(N));
  for (int j = 0; j < M; j++) {
    for (int i = 0; i < N; i++) {
      e.at(j).at(i) = (Y.at(j) >> i) & 1;
    }
  }
  auto f = [&](int left, int right, vector<int> &a) -> long long {
    int L = right - left;
    long long ans = 0;
    for (int l = 0; l < L; l++) {
      long long now = 0;
      if (a.at(left + l) == 1) {
        now = 1LL << l;
      }
      ans += now;
    }
    return ans;
  };
  long long ans = 0;
  for (int i = 0; i <= N - 2; i++) {
    long long A = 0;
    long long B = 0;
    A += f(0, i + 1, b);
    B += f(i + 1, N, b);
    for (int j = 0; j < M; j++) {
      A += f(0, i + 1, e.at(j));
      B += f(i + 1, N, e.at(j));
    }
    long long now = A + B;
    ans = max(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
