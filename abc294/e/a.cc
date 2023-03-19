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
  long long i = 1;
  int n1 = 0;
  long long i1 = 1;
  int n2 = 0;
  long long i2 = 1;
  long long ans = 0;
  while (n1 < N1 && n2 < N2) {
    long long ni;
    bool select1;
    if (i1 + L1[n1] <= i2 + L2[n2]) {
      select1 = true;
      ni = i1 + L1[n1];
    } else {
      select1 = false;
      ni = i2 + L2[n2];
    }
    if (V1[n1] == V2[n2]) {
      ans += (ni - i);
    }
    // next
    if (select1) {
      i1 = ni;
      n1++;
    } else {
      i2 = ni;
      n2++;
    }
    i = ni;
  }
  cout << ans << endl;
  return 0;
}
