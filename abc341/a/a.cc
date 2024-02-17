#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string ans;
  for (int i = 0; i < N; i++) {
    ans.push_back('1');
    ans.push_back('0');
  }
  ans.push_back('1');
  cout << ans << endl;
  return 0;
}
