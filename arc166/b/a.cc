#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const long long INF = 4e18;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

/**
 * 最小公倍数を計算する。
 * 計算量はO(log(a))
 * 制約: a > 0, b > 0
 */
template<class T> T lcm(T a, T b) {
  return a / __gcd(a, b) * b;
}

long long solve0(const vector<long long> &A, const vector<long long>& X) {
  int N = A.size();
  int K = X.size();
  if (N < K) {
    return INF;
  }

  vector<int> P(K, -1);
  for (int i = 0; i < K; i++) {
    P.at(i) = i;
  }
  long long ans = INF;
  do { // Pの順にXをx, y, zとわりあててこの順に割るとする。
    // xを試す
    vector<bool> used(N, false);
    auto f = [&](long long x) -> long long {
      long long mn = INF;
      int mn_i = -1;
      for (int n = 0; n < N; n++) {
        if (used[n]) continue;
        long long now = (x - A[n] % x) % x;
        if (now < mn) {
          mn = now;
          mn_i = n;
        }
      }
      used[mn_i] = true;
      return mn;
    };
    long long now = 0;
    for (int i = 0; i < K; i++) {
      long long now0 = f(X[P[i]]);
      now += now0;
    }
    ans = min(ans, now);
  } while (next_permutation(P.begin(), P.end()));
  return ans;
}

long long solve(const vector<long long> &A, const vector<long long>& X) {
  // 重複削除
  set<long long> st;
  for (long long x : X) {
    st.insert(x);
  }
  vector<long long> Y;
  for (long long y : st) {
    Y.push_back(y);
  }
  return solve0(A, Y);
}

int main() {
  int N;
  long long a, b, c;
  cin >> N >> a >> b >> c;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }

  long long ans = INF;
  {
    vector<long long> X;
    X.push_back(a);
    X.push_back(b);
    X.push_back(c);
    long long now = solve(A, X);
    chmin(ans, now);
  }

  {
    vector<long long> X;
    X.push_back(lcm(a, b));
    X.push_back(c);
    long long now = solve(A, X);
    chmin(ans, now);
  }

  {
    vector<long long> X;
    X.push_back(lcm(b, c));
    X.push_back(a);
    long long now = solve(A, X);
    chmin(ans, now);
  }

  {
    vector<long long> X;
    X.push_back(lcm(c, a));
    X.push_back(b);
    long long now = solve(A, X);
    chmin(ans, now);
  }

  {
    vector<long long> X;
    X.push_back(lcm(lcm(a, b), c));
    long long now = solve(A, X);
    chmin(ans, now);
  }

  cout << ans << endl;
  return 0;
}
