#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int K;
  cin >> K;
  string ans;
  for (int k = 0; k < K; k++) {
    ans += ('A' + k);
  }
  cout << ans << endl;
  return 0;
}
