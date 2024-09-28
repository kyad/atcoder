#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int ans = 0;
  for (int i = 0; i < 12; i++) {
    string S;
    cin >> S;
    if ((int)S.size() == i + 1) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
