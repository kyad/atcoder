#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  string S;
  cin >> S;
  int ans = N - (count(S.begin(), S.end(), '@') - D);
  cout << ans << endl;
  return 0;
}
