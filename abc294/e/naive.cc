#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long L;
  int N1, N2;
  cin >> L >> N1 >> N2;
  vector<long long> V1(N1), L1(N1);
  for (int n1 = 0; n1 < N1; n1++) {
    cin >> V1.at(n1) >> L1.at(n1);
  }
  vector<long long> V2(N2), L2(N2);
  for (int n2 = 0; n2 < N2; n2++) {
    cin >> V2.at(n2) >> L2.at(n2);
  }
  vector<int> A(L + 1, 0);
  vector<int> B(L + 1, 0);
  int i1 = 1;
  for (int n1 = 0; n1 < N1; n1++) {
    for (int i = i1; i < i1 + L1[n1]; i++) {
      A[i] = V1[n1];
    }
    i1 += L1[n1];
  }
  int i2 = 1;
  for (int n2 = 0; n2 < N2; n2++) {
    for (int i = i2; i < i2 + L2[n2]; i++) {
      B[i] = V2[n2];
    }
    i2 += L2[n2];
  }
  long long ans = 0;
  for (int i = 1; i <= L; i++) {
    if (A[i] == B[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
