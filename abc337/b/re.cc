#include <algorithm>
#include <cassert>
#include <iostream>
#include <regex>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  regex re(R"(A*B*C*)");
  bool ans = regex_match(S, re);
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
