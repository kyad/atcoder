#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N = 4;
  vector<int> count(4, 0);
  for (int i = 0; i < 4; i++) {
    int a;
    cin >> a;
    a--;
    count.at(a)++;
  }
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    int now = count.at(i) / 2;
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
