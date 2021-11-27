#include <iostream>
using namespace std;

int main() {
  long long A, B;
  cin >> A >> B;
  while (A > 0 && B > 0) {
    int a = A % 10;
    int b = B % 10;
    if (a + b >= 10) {
      cout << "Hard" << endl;
      return 0;
    }
    A /= 10;
    B /= 10;
  }
  cout << "Easy" << endl;
  return 0;
}
