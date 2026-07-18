#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int A, B;
    string S;
    cin >> A >> B >> S;
    if (S == "keep") {
      ans += B - A;
    }
  }
  cout << ans << '\n';
  return 0;
}
