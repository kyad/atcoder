#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N;
  cin >> N;
  string ans = S.substr(N, S.size() - 2 * N);
  cout << ans << '\n';
  return 0;
}
