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
    if ((i + 1) % 3) {
      ans.push_back('o');
    } else {
      ans.push_back('x');
    }
  }
  cout << ans << endl;
  return 0;
}
