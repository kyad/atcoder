// https://www.youtube.com/watch?v=5uVFMznaVIw&t=5456s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N, M;
  long long K;
  cin >> N >> M >> K;
  vector<long long> AA(N);
  for (int i = 0; i < N; i++) {
    cin >> AA[i];
  }

  if (N == M) {
    vector<int> ans(N, 0);
    dump(ans);
    return 0;
  }

  vector<long long> A(AA);
  sort(A.begin(), A.end());

  // S[0] = 0, S[i] = A[0] + ... + A[i - 1];
  vector<long long> S(N + 1, 0);
  for (int i = 0; i < N; i++) {
    S[i + 1] = S[i] + A[i];
  }

  long long R = K - S[N];
  map<int, long long> mp;
  for (int i = 0; i < N; i++) {
    // i人目にX票投票した時、i人目は当選確定するか？
    auto f = [&](long long X) {
      long long Y = A[i] + X + 1;
      int r = lower_bound(A.begin(), A.end(), Y) - A.begin();
      assert(0 <= r && r <= N);
      int l = N - M;
      assert(1 <= l);
      if (r < l) {
        return false;
      }
      long long sum = (r - l) * Y - (S[r] - S[l]);
      if (l <= i && i < r) {
        sum -= (Y - A[i]);
        sum += (Y - A[l - 1]);
      }
      bool ans;
      if (sum <= R - X) {
        ans = false;
      } else {
        ans = true;
      }
      return ans;
    };
    long long left = -1; // NG
    long long right = K; // OK
    while (right - left > 1) {
      long long mid = (left + right) / 2;
      assert(mid >= 0);
      if (f(mid)) {
        right = mid;
      } else {
        left = mid;
      }
    }
    long long now = right;
    if (now > R) {
      now = -1;
    }
    mp[A[i]] = now;
  }
  vector<long long> ans(N);
  for (int i = 0; i < N; i++) {
    ans[i] = mp[AA[i]];
  }
  dump(ans);
  return 0;
}
