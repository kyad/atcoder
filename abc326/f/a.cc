#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  // Bに+1, -1のいずれかをかけた和をXにできるか？
  // できたらその+1, -1を返す
  auto f = [&](vector<int> B, long long X) -> vector<int> {
    vector<int> R, S;
    int M = B.size();
    for (int m = 0; m < M / 2; m++) {
      R.push_back(B.at(m));
    }
    for (int m = M / 2; m < M; m++) {
      S.push_back(B.at(m));
    }
    // Rを整形
    vector<pair<int, long long> > r;  // [(bit, sum)]
    int K = R.size();
    {
      assert(K <= 20);
      int K2 = 1<<K;
      for (int bit = 0; bit < K2; bit++) {
        long long sum = 0;
        for (int i = 0; i < K; i++) {
          if (bit>>i&1) { // 1の時は+1方向とする
            sum += R.at(i);
          } else {
            sum -= R.at(i);
          }
        }
        r.push_back(make_pair(bit, sum));
      }
    }
    // Sを整形
    vector<long long> s;  // [sum ...]
    map<long long, int> mp;  // mp[sum] = bit
    int L = S.size();
    {
      assert(L <= 20);
      int L2 = 1<<L;
      for (int bit = 0; bit < L2; bit++) {
        long long sum = 0;
        for (int j = 0; j < L; j++) {
          if (bit>>j&1) {
            sum += S.at(j);
          } else {
            sum -= S.at(j);
          }
        }
        s.push_back(sum);
        mp[sum] = bit;
      }
      sort(s.begin(), s.end());
    }
    for (auto [bit_r, sum_r]: r) {
      // sum_r + sum_s = X --> sum_s = X - sum_r
      long long x = X - sum_r;
      auto it = lower_bound(s.begin(), s.end(), x);
      if (it != s.end() && *it == x) {
        vector<int> ans;
        for (int i = 0; i < K; i++) ans.push_back(bit_r>>i&1 ? +1 : -1);
        assert(mp.count(x) >= 1);
        int bit_s = mp[x];
        for (int j = 0; j < L; j++) ans.push_back(bit_s>>j&1 ? +1 : -1);
        assert((int)ans.size() == M);
        return ans;
      }
    }
    cout << "No" << endl;
    exit(0);
  };
  vector<int> P, Q;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      Q.push_back(A[i]);
    } else {
      P.push_back(A[i]);
    }
  }
  vector<int> dq = f(Q, Y);
  vector<int> dp = f(P, X);
  int a = 0;  // 現在の方向
  string S;
  for (int i = 0; i < N; i++) {
    int na;
    if (i % 2 == 0) {
      if (dq.at(i / 2) == +1) na = 1;
      else if (dq.at(i / 2) == -1) na = 3;
      else assert(false);
    } else {  // iが奇数
      if (dp[i / 2] == +1) na = 0;
      else if (dp[i / 2] == -1) na = 2;
      else assert(false);
    }
    int r = (na - a + 4) % 4;
    if (r == 1) S.push_back('L');
    else if (r == 3) S.push_back('R');
    else assert(false);
    a = na;
  }
  cout << "Yes" << endl;
  cout << S << endl;
  return 0;
}
