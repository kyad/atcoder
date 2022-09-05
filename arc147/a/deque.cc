#include <algorithm>
#include <deque>
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
  deque<int> dq;
  for (int n = 0; n < N; n++) {
    dq.push_back(A.at(n));
  }
  int ans = 0;
  while (dq.size() > 1) {
    int a = dq.front();
    int b = dq.back();
    dq.pop_back();
    int now = b % a;
    if (now > 0) {
      dq.push_front(now);
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
