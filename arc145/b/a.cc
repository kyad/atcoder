#include <iostream>
using namespace std;

int main() {
  long long N, A, B;
  cin >> N >> A >> B;
  if (N < A) {
    cout << 0 << endl;
    return 0;
  }
  if (A <= B) {
    long long ans =  N - A + 1;
    cout << ans << endl;
  } else {
    // Aが勝つ数を求める
    long long round = (N - (A - 1)) / A;
    long long per1 = B - 1 + 1;  // Aが勝つ
    long long ans = round * per1;
    if (((N - (A - 1)) % A) > 0) {
      long long per1 = B - 1 + 1;  // Aが勝つ
      long long count = (N - (A - 1)) % A;
      long long now = min(count, per1);
      ans += now;
    }
    cout << ans << endl;
  }
  return 0;
}
