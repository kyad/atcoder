#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

const long long INF = 4e18;
template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<tuple<int, long long, long long> > > graph(N);
  for (int m = 0; m < M; m++) {
    int U, V;
    long long B, C;
    cin >> U >> V >> B >> C;
    U--; V--;
    graph[U].push_back(make_tuple(V, B, C));
  }
  auto f = [&](double x) -> double {
    // dp[u]: uに行く時のWの最小値
    vector<double> dp(N, INF);
    dp[0] = 0;
    for (int u = 0; u < N - 1; u++) {
      for (auto [v, b, c] : graph[u]) {
        double w = x * c - b;
        chmin(dp[v], dp[u] + w);
      }
    }
    return dp[N - 1];
  };
  double left = 0;  // NG
  double right = 2e10;  // OK
  for (int i = 0; i < 100; i++) {
    double mid = (left + right) / 2;
    if (f(mid) >= 0) {  // OK
      right = mid;
    } else {
      left = mid;
    }
  }
  double ans = right;
  cout << setprecision(15) << ans << endl;
  return 0;
}
