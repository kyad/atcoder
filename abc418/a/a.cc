#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  bool ans;
  ans = (S.ends_with("tea"));
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
