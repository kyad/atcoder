#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const long long INF = 4e18;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

// m^n, O(log n)
long long power(long long m, long long n, int mod = 1e9) {
  long long a = m % mod;
  long long ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
  }
  vector<set<int> > A(M);
  for (int j = 0; j < M; j++) {
    int K;
    cin >> K;
    for (int k = 0; k < K; k++) {
      int a;
      cin >> a;
      a--;
      A.at(j).insert(a);
    }
  }
  
  int N3 = power(3, N);

  // encode(count) -> 状態sを返す
  auto encode = [&](const vector<int>& count) {
    int s = 0;
    for (int i = N - 1; i >= 0; i--) {
      s *= 3;
      s += count.at(i);
    }
    return s;
  };

  // decode(s) -> 動物園iに行った回数を返す
  auto decode = [&](int s) -> vector<int> {
    vector<int> count(N, 0);
    for (int i = 0; i < N; i++) {
      count.at(i) = s % 3;
      s /= 3;
    }
    return count;
  };

  long long ans = INF;
  for (int s = 0; s < N3; s++) {
    vector<int> count = decode(s); // count[i]: 動物園iに行った回数
    vector<int> B(M, 0);  // B[j]: 動物jを見た回数
    long long cost = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (A.at(j).contains(i)) {
          B.at(j) += count.at(i);
        }
      }
      cost += C.at(i) * count.at(i);
    }
    bool ok = true;
    for (int j = 0; j < M; j++) {
      if (B.at(j) < 2) {
        ok = false;
      }
    }
    if (ok) {
      ans = min(ans, cost);
    }
  }
  cout << ans << endl;
  return 0;
}
