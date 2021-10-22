// https://atcoder.jp/contests/abc134/tasks/abc134_e

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> dp;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    vector<int>::iterator it = upper_bound(dp.begin(), dp.end(), -A);
    if (it == dp.end()) {
      dp.push_back(-A);
    } else {
      *it = -A;
    }
  }
  cout << dp.size() << endl;
  return 0;
}
