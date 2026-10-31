#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int c = count(S.begin(), S.end(), 'o');
  if (c % 2 == 1) {
    cout << "odd" << '\n';
  } else {
    cout << "even" << '\n';
  }
  return 0;
}
