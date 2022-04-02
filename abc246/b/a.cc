#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  double d = sqrt(A * A + B * B);
  double x = (double)A / d;
  double y = (double)B / d;
  cout << x << ' ' << y << endl;
  return 0;
}
