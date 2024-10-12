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
  int ans = 0;
  for (int i = 0; i + 2 < N; i++) {
    if (S.at(i) == '#' && S.at(i + 1) == '.' && S.at(i + 2) == '#') {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
