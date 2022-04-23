#include <iostream>
#include <vector>
using namespace std;

// int(sqrt(n)) for n >= 0
const int INF = 200002;
int int_sqrt(int n) {
  if (n == 0) {
    return 0;
  }    
  int left = 0;
  int right = INF;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    long long y = (long long)mid * mid - n;
    if (y <= 0) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return left;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> count(200001, 0);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
    count.at(A.at(n))++;
  }
  long long ans = 0;
  for (int I = 2; I <= 200000; I++) {
    int r = int_sqrt(I);
    for (int J = 1; J <= r; J++) {
      if (I % J != 0) {
        continue;
      }
      int K = I / J;
      long long now;
      long long ci = count.at(I);
      long long cj = count.at(J);
      long long ck = count.at(K);
      now = ci * cj * ck;
      if (J != K) {
        now *= 2;
      }
      ans += now;
    }
  }
  // Case A_i == 1
  long long now = (long long)count[1] * (long long)count[1] * (long long)count[1];
  ans += now;
  cout << ans << endl;
  return 0;
}
