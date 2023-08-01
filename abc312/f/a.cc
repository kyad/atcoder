#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A;
  vector<int> B;
  vector<int> C;
  for (int n = 0; n < N; n++) {
    int T, X;
    cin >> T >> X;
    if (T == 0) {
      A.push_back(X);
    } else if (T == 1) {
      B.push_back(X);
    } else {
      C.push_back(X);
    }
  }
  sort(A.rbegin(), A.rend());
  sort(B.rbegin(), B.rend());
  sort(C.rbegin(), C.rend());
  const int NA = A.size();
  const int NB = B.size();
  const int NC = C.size();
  vector<long long> SA(NA + 1, 0);  // SA[a]: Aのa個(A[0]からA[a-1]まで)の和
  if (NA >= 1) {
    SA[1] = A[0];
    for (int a = 2; a <= NA; a++) {
      SA[a] = SA[a - 1] + A[a - 1];
    }
  }
  vector<long long> SB(NB + 1, 0);  // SB[b]: Bのb個(B[0]からB[b-1]まで)の和
  if (NB >= 1) {
    SB[1] = B[0];
    for (int b = 2; b <= NB; b++) {
      SB[b] = SB[b - 1] + B[b - 1];
    }
  }
  int b = 0;
  int c = 0;
  int d = 0;
  long long ans = 0;
  for (int a = min(M, NA); a >= 0; a--) {
    while (a + b + c < M) {
      if (d == 0 && c < NC) {
        d = C[c];
        c++;
      } else if (d > 0 && b < NB) {
        d--;
        b++;
      } else {
        // 何もすることができない
        break;
      }
    }
    long long now = SA[a] + SB[b];
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}
