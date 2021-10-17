// https://atcoder.jp/contests/arc128/tasks/arc128_a

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
  vector<int> ans(N, 0);
  for (int n = 0; n < N - 1; n++) {
    if (A.at(n) > A.at(n + 1)) {
      ans.at(n) = 1 - ans.at(n);
      ans.at(n + 1) = 1 - ans.at(n + 1);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }
  return 0;
}
