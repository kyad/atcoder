// https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
  }
  vector<int> v;
  v.push_back(0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      v.push_back(P[i] + P[j]);
    }
    v.push_back(P[i]);
  }
  sort(v.begin(), v.end());
  // 合計x点以上にできるか？
  int left = 0;  // できる
  int right = M + 1; // できない
  while (right - left > 1) {
    int mid = (left + right) / 2;
    int ok = false;
    for (size_t i = 0; i < v.size(); i++) {
      int a = v[i];
      vector<int>::iterator it = lower_bound(v.begin(), v.end(), mid - a);
      if (it != v.end() && a + *it <= M) {
        ok = true;
      }
    }
    if (ok) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << left << endl;
  return 0;
}
