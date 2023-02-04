#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> cumsum(const vector<long long> &A, int K) {
  int N = A.size();
  vector<long long> S(N, 0);
  for (int n = 0; n < N; n++) {
    if (n < K) {
      S.at(n) = A.at(n);
    } else {
      S.at(n) = A.at(n) + S.at(n - K);
    }
  }
  return S;
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<vector<long long> > A(K);
  for (int n = 0; n < N; n++) {
    long long a;
    cin >> a;
    for (int k = 0; k < K; k++) {
      if (n >= k) {
        A[k].push_back(a);
      }
    }
  }
  vector<vector<long long> > S(K);
  for (int k = 0; k < K; k++) {
    S[k] = cumsum(A[k], K);
  }
  int Q;
  cin >> Q;

  auto solve = [&](const vector<long long> &S, int l, int r) -> bool {
    assert(l >= 0);
    assert(r >= 0);
    int s = r - (K - 1);
    assert(s >= 0);
    bool ans = true;
    long long Q = S[s];
    int z = l + (s % K) - K;
    if (z >= 0) {
      Q -= S[z];
    }
    for (int cnt = 0; cnt < K - 1; cnt++) {
      int x = r - cnt;
      long long P = S[x];
      int y = l + (x % K) - K;
      if (y >= 0) {
        P -= S[y];
      }
      long long now = P - Q;
      if (now != 0) {
        ans = false;
        break;
      }
    }
    return ans;
  };
  
  for (int q = 0; q < Q; q++) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    int k = l % K;
    bool ans = solve(S[k], l - k, r - k);
    cout << (ans ? "Yes" : "No") << '\n';
  }
  return 0;
}
