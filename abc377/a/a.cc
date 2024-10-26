#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<int> count(3, 0);
  for (int i = 0; i < 3; i++) {
    int j = S.at(i) - 'A';
    if (0 <= j && j <= 2) {
      count.at(j)++;
    }
  }
  bool ans = false;
  if (count.at(0) == 1 && count.at(1) == 1 && count.at(2) == 1) {
    ans = true;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
