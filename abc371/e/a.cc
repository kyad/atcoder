#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  const int MX = 2e5;
  vector<vector<int> > idxs(MX + 1);
  for (int i = 0; i < N; i++) {
    idxs.at(A.at(i)).push_back(i);
  }
  // 値毎に集計する
  long long ans = 0;
  for (int a = 1; a <= MX; a++) {
    int M = idxs.at(a).size();
    long long now = 0;
    int prev = -1;
    for (int j = 0; j < M; j++) {
      int idx = idxs.at(a).at(j);
      long long left = idx - prev;
      long long right = N - idx;
      now += left * right;
      prev = idx;
    }
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
