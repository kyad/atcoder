#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<bool> cut(360, false);
  cut.at(0) = true;
  int idx = 0;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    idx = idx + 360 - A;
    idx %= 360;
    cut.at(idx) = true;
  }
  int ans = 0;
  int sum = 0;
  for (int n = 359; n >= 0; n--) {
    if (cut.at(n)) {
      ans = max(ans, sum + 1);
      sum = 0;
    } else {
      sum++;
    }
  }
  cout << ans << endl;
  return 0;
}
