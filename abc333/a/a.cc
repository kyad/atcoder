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
    ans += to_string(N);
  }
  cout << ans << endl;
  return 0;
}
