#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  long long A, B;
  cin >> A >> B;
  long long g = __gcd(A, B);
  long long c = A / g;
  const long long INF = 1000000000000000000;
  if (c > INF / B) {
    cout << "Large" << endl;
  } else {
    cout << c * B << endl;
  }
  return 0;
}
