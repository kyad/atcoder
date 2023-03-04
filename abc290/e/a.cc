#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  vector<vector<int> > P(N + 1);
  for (int n = 1; n <= N; n++) {
    int x = A[n];
    P[x].push_back(n);
  }
  long long S = 0;
  for (int x = 1; x <= N; x++) {
    int M = P[x].size();
    // M == 0 も含む
    int l = 1;
    int r = M;
    while (l < r) {
      if (P[x][l - 1] <= N + 1 - P[x][r - 1]) {
        S += (long long)P[x][l - 1] * (r - l);
        l++;
      } else {
        S += (long long)(N + 1 - P[x][r - 1]) * (r - l);
        r--;
      }
    }
  }
  long long T = 0;
  for (int i = 1; i <= N; i++) {
    T += (long long)(N + 1 - i) * (i / 2);
  }
  long long ans = T - S;
  cout << ans << endl;
  return 0;
}
