#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  string T = S.substr(3, 3);
  int a = stoi(T);
  bool ans = (1 <= a && a <= 349);
  if (a == 316) {
    ans = false;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
