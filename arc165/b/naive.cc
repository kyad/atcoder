// TLE

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> P(N, -1);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
  }
  vector<int> ans(N);
  for (int n = 0; n < N; n++) {
    ans[0] = -1;
  }
  for (int i = 0; i <= N - K; i++) {
    vector<int> Q(P);
    sort(Q.begin() + i, Q.begin() + i + K);
    ans = max(ans, Q);
  }
  dumpvec(ans);
  return 0;
}
