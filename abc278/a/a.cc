#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> ans(N, 0);
  int i = 0;
  for (int k = K; k < N; k++) {
    ans[i] = A[k];
    i++;
  }
  for (int n = 0; n < N; n++) {
    cout << ans[n] << (n == N - 1 ? '\n' : ' ');
  }
  return 0;
}
