#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  long long d = 0;
  queue<long long> q;
  for (int qi = 0; qi < Q; qi++) {
    int task = 0;
    cin >> task;
    if (task == 1) {
      q.push(d);
    } else if (task == 2) {
      long long T;
      cin >> T;
      d += T;
    } else {
      long long H;
      cin >> H;
      int ans = 0;
      while (!q.empty()) {
        long long front = q.front();
        long long h = d - front;
        if (h >= H) {
          ans++;
          q.pop();
        } else {
          break;
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
