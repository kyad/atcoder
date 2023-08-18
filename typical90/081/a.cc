#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  const int M = 5000;
  vector<vector<long long> > S(M + 1, vector<long long>(M + 1, 0));
  for (int n = 0; n < N; n++) {
    int A, B;
    cin >> A >> B;
    S[B][A]++;
  }
  for (int b = 0; b < M; b++) {
    for (int a = 0; a < M; a++) {
      S[b][a + 1] += S[b][a];
    }
  }
  for (int a = 0; a < M; a++) {
    for (int b = 0; b < M; b++) {
      S[b + 1][a] += S[b][a];
    }
  }
  long long ans = -1;
  for (int b = 1; b < M; b++) {
    if (b + K > M) {
      break;
    }
    for (int a = 1; a < M; a++) {
      if (a + K > M) {
        break;
      }
      const long long now = S[b + K][a + K] - S[b + K][a - 1] - S[b - 1][a + K] + S[b - 1][a - 1];
      ans = max(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}
