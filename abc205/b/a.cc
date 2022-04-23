// https://atcoder.jp/contests/abc205/tasks/abc205_b

#include <algorithm>
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
  sort(A.begin(), A.end());
  int ans = true;
  for (int n = 0; n < N; n++) {
    if (n + 1 != A.at(n)) {
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
