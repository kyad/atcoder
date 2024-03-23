#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;
  vector<int> S;
  for (char c : s) {
    S.push_back(c - '0');
  }
  assert((int)S.size() == N);
  vector<long long> C(N);
  for (int n = 0; n < N; n++) {
    cin >> C.at(n);
  }
  auto f = [&](int u0) {
    // 初期状態(1文字目が揃ってない)
    vector<int> U;
    for (int i = 0; i < 2; i++) {
      U.push_back(u0);
    }
    int now = 1 - u0;
    for (int i = 0; i < N - 2; i++) {
      U.push_back(now);
      now = 1 - now;
    }
    assert((int)U.size() == N);
    // 初期状態のコスト
    long long cost = 0;
    for (int i = 0; i < N; i++) {
      if (S[i] != U[i]) {
        cost += C[i];
      }
    }
    // i=2,...,N-1文字目が揃ってない時のコスト
    long long ans = cost;
    for (int i = 1; i <= N - 2; i++) {
      long long d;
      if (U[i] == S[i]) {
        d = C[i];
      } else {
        d = -C[i];
      }
      U.at(i) = 1 - U.at(i);
      cost += d;
      ans = min(ans, cost);
    }
    return ans;
  };
  long long ans0 = f(0);
  long long ans1 = f(1);
  long long ans = min(ans0, ans1);
  cout << ans << endl;
  return 0;
}
