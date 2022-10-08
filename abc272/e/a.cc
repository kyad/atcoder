#include <iostream>
#include <map>
#include <vector>
using namespace std;

int ceil(int a, int b) {
  return (a + b - 1) / b;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  vector<map<int, int> > dp(M + 1);
  for (int i = 1; i <= N; i++) {
    int k;
    if (A[i] >= 0) {
      k = 0;
    } else {
      k = ceil(-A[i], i);
    }
    for (int l = k; l <= k + ceil(N, i); l++) {
      if (l > M) {
        break;
      }
      int value = A[i] + l * i;
      if (value >= N) {
        break;
      }
      dp[l][value]++;
    }
  }
  for (int i = 1; i <= M; i++) {
    int mex = 0;
    for (int j = 0; j < N; j++) {
      if (dp[i][j] > 0) {
        mex = j + 1;
      } else {
        break;
      }
    }
    cout << mex << endl;
  }
  return 0;
}
