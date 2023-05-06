#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int f(const string& S, int K) {
  vector<int> A;
  A.push_back(0);
  for (char c : S) {
    if (c == 'o') {
      A.back()++;
    } else {
      A.push_back(0);
    }
  }
  int N = A.size();
  A.insert(A.begin(), 0);  // 0-indexed --> 1-indexed
  vector<int> sum(A);
  for (int n = 1; n <= N; n++) {
    sum[n] += sum[n - 1];
  }
  int ans = 0;
  for (int l = 1; l <= N - K; l++) {
    int r = l + K;
    int now = sum[r] - sum[l - 1] + K;
    ans = max(ans, now);
  }
  return ans;
}

int main() {
  long long N, M, K;
  cin >> N >> M >> K;
  string S;
  cin >> S;
  if (M == 1) {
    long long ans = f(S, K);
    cout << ans << endl;
    return 0;
  }
  long long X = count(S.begin(), S.end(), 'x');
  long long C = K / X;  // C<=M
  C = min(C, M - 2);
  K -= C * X;
  long long ans = C * N + f(S + S, K);
  cout << ans << endl;
  return 0;
}
