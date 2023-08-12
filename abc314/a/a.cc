#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
  cout << "3.";
  for (int i = 0; i < N; i++) {
    cout << S.at(i);
  }
  cout << endl;
  return 0;
}
