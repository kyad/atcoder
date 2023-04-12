#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > R(M);
  for (int m = 0; m < M; m++) {
    int K;
    cin >> K;
    for (int k = 0; k < K; k++) {
      int r;
      cin >> r;
      r--;
      R.at(m).push_back(r);
    }
  }
  vector<vector<int> > ms(N);
  for (int m = 0; m < M; m++) {
    for (int r : R[m]) {
      ms[r].push_back(m);
    }
  }
  vector<bool> used(M, false);
  vector<int> T(N, -1);
  T[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    for (int m : ms[n]) {
      if (used[m]) {
        continue;
      }
      for (int r : R[m]) {
        if (T[r] >= 0) {
          continue;
        }
        T[r] = T[n] + 1;
        q.push(r);
      }
      used[m] = true;
    }
  }
  for (int n = 0; n < N; n++) {
    cout << T[n] << '\n';
  }
  return 0;
}
