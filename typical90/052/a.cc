#include <iostream>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;

int main() {
  int N;
  cin >> N;
  mint ans = 1;
  for (int n = 0; n < N; n++) {
    mint now = 0;
    for (int i = 0; i < 6; i++) {
      int A;
      cin >> A;
      now += A;
    }
    ans *= now;
  }
  cout << ans.val() << endl;
  return 0;
}
