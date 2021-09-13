// https://atcoder.jp/contests/abc023/tasks/abc023_d
// https://drken1215.hatenablog.com/entry/2021/06/12/113100

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool check(int N, vector<int> H, vector<int> S, long long Q) {
  if (Q < 0) {
    return false;
  }
  priority_queue<long long> deadline;
  for (int n = 0; n < N; n++) {
    if (Q < H[n]) {
      return false;
    }
    deadline.push((Q - H[n]) / S[n]);
  }
  bool ans = true;
  for (int n = N - 1; n >= 0; n--) {
    if (deadline.top() < n) {
      ans = false;
      break;
    }
    deadline.pop();
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  vector<int> S(N);
  for (int n = 0; n < N; n++) {
    cin >> H.at(n) >> S.at(n);
  }
  const long long INF = (long long)100000 * 1000000000 + 1;
  long long left = -1;
  long long right = INF;
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    if (check(N, H, S, mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  cout << right << endl;
  return 0;
}
