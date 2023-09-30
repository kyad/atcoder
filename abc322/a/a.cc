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
  int ans = S.find("ABC");
  if (ans >= 0) {
    ans++;
  }
  cout << ans << endl;
  return 0;
}
