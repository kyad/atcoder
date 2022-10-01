#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a = N / 16;
  int b = N % 16;
  char c = (a >= 10 ? ('A' + (a - 10)) : ('0' + a));
  char d = (b >= 10 ? ('A' + (b - 10)) : ('0' + b));
  cout << c << d << endl;
  return 0;
}
