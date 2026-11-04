#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  string ans;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    if (abs(A - B) >= K) {
      ans.push_back('L');
    } else {
      ans.push_back('S');
    }
  }
  cout << ans << '\n';
  return 0;
}
