// https://atcoder.jp/contests/abc106/tasks/abc106_d

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  map<pair<int, int>, int> train;  // (left, right), value
  for (int m = 0; m < M; m++) {
    int L, R;
    cin >> L >> R;
    train[make_pair(L - 1, R - 1)]++;
  }
  vector<vector<int> > ans(N, vector<int>(N, 0));
  for (int start = 0; start < N; start++) {
    for (map<pair<int, int>, int>::iterator it = train.begin(); it != train.end(); it++) {
      int left = it->first.first;
      int right = it->first.second;
      int value = it->second;
      if (left < start) {
        continue;
      }
      ans[start][right] += value;
    }
    for (int end = 1; end < N; end++) {
      ans[start][end] += ans[start][end - 1];
    }
  }
  for (int i = 0; i < Q; i++) {
    int p, q;
    cin >> p >> q;
    cout << ans[p - 1][q - 1] << endl;
  }
  return 0;
}
