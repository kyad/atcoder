#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<int, priority_queue<int> > mx;
  for (int n = 0; n < N; n++) {
    int x, y;
    cin >> x >> y;
    mx[x].push(y);
  }
  int count = 0;
  for (map<int, priority_queue<int> >::iterator i = mx.begin(); i != mx.end(); i++) {
    for (map<int, priority_queue<int> >::iterator j = next(i); j != mx.end(); j++) {
      priority_queue<int> pq_i(i->second);
      priority_queue<int> pq_j(j->second);
      int count_y = 0;
      while (!pq_i.empty() && !pq_j.empty()) {
        if (pq_i.top() == pq_j.top()) {
          count_y++;
          pq_i.pop();
          pq_j.pop();
        } else if (pq_i.top() > pq_j.top()) {
          pq_i.pop();
        } else {
          pq_j.pop();
        }
      }
      count += count_y * (count_y - 1) / 2;
    }
  }
  cout << count << endl;
  return 0;
}
