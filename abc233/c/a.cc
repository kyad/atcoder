#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N, X;
  cin >> N >> X;
  vector<vector<int> > A(N);
  vector<int> L(N);
  for (int n = 0; n < N; n++) {
    cin >> L.at(n);
    for (int l = 0; l < L.at(n); l++) {
      int a;
      cin >> a;
      A.at(n).push_back(a);
    }
  }
  int M = 1;
  for (long long n = 0; n < N; n++) {
    M *= L.at(n);
  }
  int ans = 0;
  for (int m = 0; m < M; m++) {
    int temp = m;
    long long XX = X;
    bool ok = true;
    for (int n = 0; n < N; n++) {
      int idx = temp % L[n];
      if (XX % A[n][idx] != 0) {
        ok = false;
        break;
      }
      XX /= A[n][idx];
      temp /= L[n];
    }
    if (ok && XX == 1) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
