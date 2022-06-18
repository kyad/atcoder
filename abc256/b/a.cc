#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int P = 0;
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  int B = 0;
  for (int n = 0; n < N; n++) {
    B = B << A[n];
    B += (1<<A[n]);
    int C = B >> 4;
    int now = __builtin_popcount(C);
    P += now;
    B = B & 15;
  }
  cout << P << endl;
  return 0;
}
