#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
  }
  auto dist = [&](int i,int j) -> long long {
    long long ans = (X.at(i) - X.at(j)) * (X.at(i) - X.at(j));
    ans += (Y.at(i) - Y.at(j)) * (Y.at(i) - Y.at(j));
    return ans;
  };
  int N2 = 1<<N;
  const long long INF = 4e18;
  vector<vector<long long> > dp(N2, vector<long long>(N, INF));
  dp.at(1).at(0) = 0;
  for (int s = 1; s < N2; s++) {
    for (int l = 0; l < N; l++) {
      for (int nl = 1; nl < N; nl++) {
        if (s>>nl&1) {
          continue;
        }
        int ns = s | (1<<nl);
        chmin(dp.at(ns).at(nl), dp.at(s).at(l) + dist(l, nl));
      }
    }
  }
  long long ans = INF;
  for (int l = 1; l < N; l++) {
    chmin(ans, dp.at(N2 - 1).at(l) + dist(l, 0));
  }
  cout << ans << '\n';
  return 0;
}
