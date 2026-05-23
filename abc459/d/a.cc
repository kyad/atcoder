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
    string S;
    cin >> S;
    int N = S.size();
    vector<int> count(26, 0);
    for (char c: S) {
      int a = c - 'a';
      count.at(a)++;
    }
    priority_queue<pair<int, int> > pq;
    for (int a = 0; a < 26; a++) {
      pq.push(make_pair(count.at(a), a));
    }
    string U;
    int prev_a = -1;
    bool ok = true;
    for (int i = 0; i < N; i++) {
      auto [cnt1, a1] = pq.top(); pq.pop();
      auto [cnt2, a2] = pq.top(); pq.pop();
      assert(0 < cnt1);
      if (prev_a != a1) {
        U.push_back('a' + a1);
        prev_a = a1;
        pq.push(make_pair(cnt2, a2));
        pq.push(make_pair(cnt1 - 1, a1));
      } else {
        if (cnt2 == 0) {
          ok = false;
          break;
        }
        U.push_back('a' + a2);
        prev_a = a2;
        pq.push(make_pair(cnt2 - 1, a2));
        pq.push(make_pair(cnt1, a1));
      }
    }
    if (ok) {
      cout << "Yes\n";
      cout << U << '\n';
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
