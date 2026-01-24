#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int i = count(S.begin(), S.end(), 'i');
  int j = count(S.begin(), S.end(), 'j');
  int ans = i + j;
  cout << ans << '\n';
  return 0;
}
