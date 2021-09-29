// https://atcoder.jp/contests/joi2013ho/tasks/joi2013ho1

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> B;
  int count = 0;
  int prev = -1;
  for (int n = 0; n < N; n++) {
    if (prev == A.at(n)) {
      B.push_back(count);
      count = 1;
    } else {
      count++;
    }
    prev = A.at(n);
  }
  B.push_back(count);
  int ans = 0;
  int len = (int)B.size();
  for (int i = 0; i < len; i++) {
    // middle
    int temp = B.at(i);
    if (i - 1 >= 0) {
      temp += B.at(i - 1);
    }
    if (i + 1 <= len - 1) {
      temp += B.at(i + 1);
    }
    ans = max(ans, temp);
    // left
    if (i - 1 >= 0 && B.at(i - 1) == 1 && i - 2 >= 0) {
      ans = max(ans, B.at(i) + 1 + B.at(i - 2));
    }
    // right
    if (i + 1 <= len - 1 && B.at(i + 1) == 1 && i + 2 <= len - 1) {
      ans = max(ans, B.at(i) + 1 + B.at(i + 2));
    }
  }
  cout << ans << endl;
  return 0;
}
