#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int N, D;
    cin >> N >> D;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
      cin >> A.at(i);
    }
    for (int i = 0; i < N; i++) {
      cin >> B.at(i);
    }
    deque<int> q;
    for (int i = 0; i < N; i++) {
      // 仕入れ
      for (int j = 0; j < A.at(i); j++) {
        q.push_back(i);
      }
      // 使用
      for (int j = 0; j < B.at(i); j++) {
        q.pop_front();
      }
      // 処分
      while (!q.empty()) {
        if (q.front() <= i - D) {
          q.pop_front();
        } else {
          break;
        }
      }
    }
    int ans = q.size();
    cout << ans << '\n';
  }
  return 0;
}
