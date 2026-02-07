#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string N;
  cin >> N;
  bool ans = N[0] == N[1] && N[1] == N[2];
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
