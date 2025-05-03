#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<int> A(26, false);
  for (char c : S) {
    int a = c - 'a';
    A.at(a) = true;
  }
  for (int i = 0; i < 26; i++) {
    if (A.at(i) == false) {
      char c = 'a' + i;
      cout << c << endl;
      return 0;
    }
  }
  return 0;
}
