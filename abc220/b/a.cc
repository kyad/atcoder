#include <iostream>
using namespace std;

int main() {
  int K;
  cin >> K;
  string A, B;
  cin >> A >> B;
  long long ans;
  long long a = 0, b = 0;
  for (size_t i = 0; i < A.size(); i++) {
    a *= K;
    a += (A.at(i) - '0');
  }
  for (size_t i = 0; i < B.size(); i++) {
    b *= K;
    b += (B.at(i) - '0');
  }
  ans = a * b;
  cout << ans << endl;
  return 0;
}
