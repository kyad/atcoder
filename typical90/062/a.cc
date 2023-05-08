#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n) >> B.at(n);
    A.at(n)--;
    B.at(n)--;
  }
  // inv[k]: A[j] = kなるjの集合
  auto inv = [](const vector<int>& A) -> vector<vector<int> > {
    int N = A.size();
    vector<vector<int> > inv(N);
    for (int j = 0; j < N; j++) {
      int k = A[j];
      inv[k].push_back(j);
    }
    return inv;
  };
  vector<vector<int> > invA = inv(A);
  vector<vector<int> > invB = inv(B);
  
  queue<int> q;
  set<int> selected;
  for (int i = 0; i < N; i++) {
    if (A[i] == i || B[i] == i) {
      q.push(i);
      selected.insert(i);
    }
  }

  vector<int> ans;
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    selected.insert(k);
    ans.push_back(k);
    for (int j : invA[k]) {
      if (selected.count(j) == 0) {
        q.push(j);
        selected.insert(j);
      }
    }
    for (int j : invB[k]) {
      if (selected.count(j) == 0) {
        q.push(j);
        selected.insert(j);
      }
    }
  }

  if ((int)ans.size() != N) {
    cout << -1 << endl;
  } else {
    reverse(ans.begin(), ans.end());
    for (int a : ans) {
      cout << (a + 1) << '\n';
    }
  }

  return 0;
}
