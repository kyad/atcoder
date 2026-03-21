#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  string X, Y;
  cin >> X >> Y;
  string YX = '_' + Y + X;
  int Q;
  cin >> Q;
  long long MX = 1000000000000000000LL;
  vector<long long> S;
  S.push_back(0);  // S0
  S.push_back(X.size());  // S1=1
  S.push_back(Y.size());  // S2=1
  while (true) {
    int n = S.size();
    long long nx = S.at(n - 1) + S.at(n - 2);
    S.push_back(nx);
    if (nx > MX) {
      break;
    }
  }
  S.at(1) = 0; // 便宜上こうする
  int N = S.size();
  // A[i][a]: Siに含まれるaの個数
  vector<vector<long long> > A(N, vector<long long>(26, 0));
  // A1
  for (char c : X) {
    int a = c - 'a';
    A.at(1).at(a)++;
  }
  // A2
  for (char c : Y) {
    int a = c - 'a';
    A.at(2).at(a)++;
  }
  // A3~A[N-1]
  for (int i = 3; i < N; i++) {
    for (int a = 0; a < 26; a++) {
      A.at(i).at(a) = A.at(i - 1).at(a) + A.at(i - 2).at(a);
    }
  }
  // 1~k文字目にcが含まれる個数
  auto f = [&](long long k, char c) -> long long {
    if (k == 0) {
      return 0;
    }
    int a = c - 'a';
    set<int> is;
    while (k > S.at(3)) {
      auto it = upper_bound(S.begin(), S.end(), k);
      assert(it != S.begin());
      it = prev(it);
      int i = it - S.begin();
      is.insert(i);
      k -= S.at(i);
    }
    long long ans = 0;
    for (int i : is) {
      long long now = A.at(i).at(a);
      ans += now;
    }
    // k文字目までは愚直に数える
    for (int i = 1; i <= k; i++) {
      if (YX.at(i) == c) {
        ans++;
      }
    }
    return ans;
  };

  for (int qi = 0; qi < Q; qi++) {
    long long L, R;
    char C;
    cin >> L >> R >> C;
    long long ans = f(R, C) - f(L - 1, C);
    cout << ans << '\n';
  }
  return 0;
}
