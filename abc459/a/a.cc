#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int X;
  cin >> X;
  X--;
  string A = "HelloWorld";
  string ans;
  for (int i = 0; i < 10; i++) {
    if (i == X) {
      continue;
    }
    ans.push_back(A.at(i));
  }
  cout << ans << '\n';
  return 0;
}
