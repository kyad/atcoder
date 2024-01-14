#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string ans = "L";
  for (int i = 0; i < N; i++) {
    ans.push_back('o');
  }
  ans = ans + "ng";
  cout << ans << endl;
  return 0;
}
