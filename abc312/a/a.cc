#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  bool ans = S == "ACE" || S == "BDF" || S == "CEG" || S == "DFA" || S == "EGB" || S == "FAC" || S == "GBD";
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
