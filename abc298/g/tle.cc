#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <boost/unordered_map.hpp>

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int H, W, T;
  cin >> H >> W >> T;
  vector<vector<long long> > S(H + 1, vector<long long>(W + 1, 0));
  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= W; x++) {
      cin >> S.at(y).at(x);
    }
  }
  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= W; x++) {
      S[y][x] += S[y - 1][x];
    }
  }
  for (int x = 1; x <= W; x++) {
    for (int y = 1; y <= H; y++) {
      S[y][x] += S[y][x - 1];
    }
  }
  // [x0, x1] * [y0, y1]のイチゴの個数
  auto g = [&](int y0, int x0, int y1, int x1) -> long long {
    long long ans = S[y1][x1] + S[y0 - 1][x0 - 1] - S[y1][x0 - 1] - S[y0 - 1][x1];
    return ans;
  };
  vector<long long> Ls;
  for (int si = 1; si <= H; si++) {
    for (int sj = 1; sj <= W; sj++) {
      for (int ti = si; ti <= H; ti++) {
        for (int tj = sj; tj <= W; tj++) {
          long long L = g(si, sj, ti, tj);
          Ls.push_back(L);
        }
      }
    }
  }

  const long long INF = 4e18;
  long long ans = INF;
  for (long long L : Ls) {
    boost::unordered_map<tuple<int, int, int, int, int>, long long> dp;
    auto f = [&](auto f, int y0, int x0, int y1, int x1, int T) -> long long {
      auto key = make_tuple(y0, x0, y1, x1, T);
      if (dp.count(key) > 0) {
        return dp[key];
      }
      if (T == 0) {
        long long ans = g(y0, x0, y1, x1);
        if (ans < L) {
          ans = INF;
        }
        return dp[key] = ans;
      }
      long long ans = INF;
      for (int y = y0 + 1; y <= y1; y++) {
        for (int t = 0; t <= T - 1; t++) {
          long long M1 = f(f, y0, x0, y - 1, x1, t);
          long long M2 = f(f, y, x0, y1, x1, T - 1 - t);
          long long M = max(M1, M2);
          chmin(ans, M);
        }
      }
      for (int x = x0 + 1; x <= x1; x++) {
        for (int t = 0; t <= T - 1; t++) {
          long long M1 = f(f, y0, x0, y1, x - 1, t);
          long long M2 = f(f, y0, x, y1, x1, T - 1 - t);
          long long M = max(M1, M2);
          chmin(ans, M);
        }
      }
      return dp[key] = ans;
    };
    long long now = f(f, 1, 1, H, W, T) - L;
    chmin(ans, now);
  }
  cout << ans << endl;
  return 0;
}
