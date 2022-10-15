#include <iostream>
#include <vector>
using namespace std;

int f (int k) {
  if (k == 0) {
    return 1;
  }
  return k * f(k - 1);
}

int main() {
  int N;
  cin >> N;
  cout << f(N) << endl;
  return 0;
}
