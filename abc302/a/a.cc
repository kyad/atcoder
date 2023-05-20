#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> T ceildiv(T a, T b) {
  return (a + b - 1) / b;
}

int main() {
  long long A, B;
  cin >> A >> B;
  cout << ceildiv(A, B) << endl;

  return 0;
}
