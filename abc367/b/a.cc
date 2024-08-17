#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string X;
  cin >> X;
  // Cut 0
  while (X.back() == '0') {
    X.pop_back();
  }
  // Cut .
  if (X.back() == '.') {
    X.pop_back();
  }
  cout << X << endl;
  return 0;
}
