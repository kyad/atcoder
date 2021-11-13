#include <cmath>
#include <iostream>
using namespace std;

int main() {
  long long N;
  cin >> N;
  int A_max = int(cbrt(N + 0.1));
  //cout << "A_max=" << A_max << endl;
  long long ans = 0;
  for (int A = 1; A <= A_max; A++) {
    int B_max = int(sqrt(N / A + 0.1));
    for (int B = A; B <= B_max; B++) {
      long long C = N / (A * B);
      if (C < B) {
        continue;
      }
      ans += (C - B + 1);
      //cout << "hoge A=" << A <<  " B=" << B << " C=" << C << " ADD=" << (C - B + 1) << " ans=" << ans << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
