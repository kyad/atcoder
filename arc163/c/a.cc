// https://atcoder.jp/contests/arc163/editorial/6695

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<int> f(int N) {
  vector<int> ans;
  for (int n = 2; n <= N; n++) {
    ans.push_back((n - 1) * n);
  }
  return ans;
}

void testcase() {
  int N;
  cin >> N;
  if (N == 1) {
    cout << "Yes" << '\n';
    cout << 1 << endl;
    return;
  } else if (N == 2) {
    cout << "No" << '\n';
    return;
  }
  cout << "Yes" << '\n';
  vector<int> ans = f(N);
  if (find(ans.begin(), ans.end(), N) == ans.end()) {
    ans.push_back(N);
  } else {
    ans = f(N - 1);
    ans.push_back(N - 1);
    for (int &a : ans) {
      a *= 2;
    }
    ans.push_back(2);
  }
  for (int a : ans) {
    cout << a << ' ';
  }
  cout << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    testcase();
  }
  return 0;
}
