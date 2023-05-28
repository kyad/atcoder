#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool> > B(N, vector<bool>(N, true));  // 不仲である可能性がある
  for (int i = 0; i < M; i++) {
    vector<int> A(N);
    for (int n = 0; n < N; n++) {
      cin >> A.at(n);
      A[n]--;
    }
    for (int n = 0; n < N - 1; n++) {
      int a = A[n];
      int b = A[n + 1];
      B[a][b] = false;
      B[b][a] = false;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (B[i][j]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
