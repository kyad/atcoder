#include <iostream>
#include <vector>
using namespace std;

long long f(long long X, int i) {
  for (int j = 0; j < i; j++) {
    X /= 10;
  }
  int a = X % 10;
  X /= 10;
  if (a >= 5) {
    X++;
  }
  for (int j = 0; j < i + 1; j++) {
    X *= 10;
  }
  return X;
}

int main() {
  long long X;
  int K;
  cin >> X >> K;
  for (int i = 0; i < K; i++) {
    X = f(X, i);
  }
  cout << X << endl;
  return 0;
}
