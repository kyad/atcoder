#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  vector<int> ans(N, 0);
  for (int j = 0; j < M; j++) {
    string T;
    cin >> T;
    int idx = -1;
    for (int i = 0; i < N; i++) {
      if (S.at(i) == T) {
        if (idx == -2) {
        } else if (idx == -1) {
          idx = i;
        } else {
          idx = -2;
        }
      }
    }
    if (idx >= 0) {
      ans.at(idx)++;
      continue;
    }
    idx = -1;
    for (int i = 0; i < N; i++) {
      if (S.at(i).size() == T.size()) {
        int diff = 0;
        for (size_t k = 0; k < S.at(i).size(); k++) {
          if (S.at(i).at(k) != T.at(k)) {
            diff++;
          }
        }
        if (diff == 1) {
          if (idx == -2) {
          } else if (idx == -1) {
            idx = i;
          } else {
            idx = -2;
          }
        }
      }
    }
    if (idx >= 0) {
      ans.at(idx)++;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans.at(i) << '\n';
  }
  return 0;
}
