#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int a = S.at(0) - '0';
  int b = S.at(2) - '0';
  int ans = a * b;
  cout << ans << endl;
  return 0;
}
