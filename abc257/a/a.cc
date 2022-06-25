#include <iostream>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  string str = "";
  for (char c = 'A'; c <= 'Z'; c++) {
    for (int n = 0; n < N; n++) {
      str += c;
    }
  }
  cout << str[X - 1] << endl;
  return 0;
}
