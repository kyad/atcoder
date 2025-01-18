#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long X;
  cin >> X;
  long long fact = 1;
  for (long long i = 1;; i++) {
    fact *= i;
    if (fact == X) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
