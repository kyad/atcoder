#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool f(int N) {
  int c = N % 10;
  int b = (N / 10) % 10;
  int a = N / 100;
  return (a * b == c);
}

int main() {
  int N;
  cin >> N;
  while (N < 1000) {
    if (f(N)) {
      break;
    }
    N++;
  }
  cout << N << endl;
  return 0;
}
