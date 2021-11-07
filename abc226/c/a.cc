#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> T(N);
  vector<int> K(N);
  vector<vector<int> > A(N);
  for (int n = 0; n < N; n++) {
    cin >> T.at(n) >> K.at(n);
    for (int k = 0; k < K.at(n); k++) {
      int a;
      cin >> a;
      a--;
      A.at(n).push_back(a);
    }
  }
  vector<bool> needed(N, false);
  queue<int> q;
  q.push(N - 1);
  needed.at(N - 1) = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (size_t i = 0; i < A.at(u).size(); i++) {
      int v = A[u][i];
      if (needed[v] == true) {
        continue;
      }
      needed[v] = true;
      q.push(v);
    }
  }
  long long ans = 0;
  for (int n = 0; n < N; n++) {
    if (needed[n]) {
      ans += T.at(n);
    }
  }
  cout << ans << endl;
  return 0;
}
