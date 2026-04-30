#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> T(M);
  for (int j = 0; j < M; j++) {
    cin >> T.at(j);
  }
  vector<vector<int>> S(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> S.at(i).at(j);
    }
  }
  vector<int> is;
  for (int i = 0; i < N; i++) {
    bool ok = true;
    for (int j = 0; j < M; j++) {
      if (S.at(i).at(j) < T.at(j)) {
        ok = false;
      }
    }
    if (ok) {
      is.push_back(i);
    }
  }
  vector<int> ans;
  if ((int)is.size() <= K) {
    for (int i : is) {
      ans.push_back(i);
    }
  } else {
    vector<int> P(N, 0);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        P.at(i) += S.at(i).at(j);
      }
    }
    vector<int> ps;
    for (int i : is) {
      ps.push_back(P.at(i));
    }
    sort(ps.begin(), ps.end());
    reverse(ps.begin(), ps.end());
    int B = ps.at(K - 1);
    for (int i : is) {
      if (P.at(i) >= B) {
        ans.push_back(i);
      }
    }
  }
  for (int i : ans) {
    cout << (i + 1) << '\n';
  }
  return 0;
}
