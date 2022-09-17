#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int N = 10;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  int A = N;
  int B = -1;
  int C = N;
  int D = -1;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (S[y][x] == '#') {
        A = min(A, y);
        B = max(B, y);
        C = min(C, x);
        D = max(D, x);
      }
    }
  }
  A++;
  B++;
  C++;
  D++;
  cout << A << ' ' << B << endl;
  cout << C << ' ' << D << endl;
  return 0;
}
