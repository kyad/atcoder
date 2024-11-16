#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string N;
  cin >> N;
  vector<int> count(10, 0);
  for (char c : N) {
    int a = c - '0';
    count.at(a)++;
  }
  bool ans = (count.at(1) == 1 && count.at(2) == 2 && count.at(3) == 3);
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
