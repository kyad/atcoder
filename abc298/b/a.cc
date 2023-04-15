#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > rot(const vector<vector<int> > &A) {
  int N = A.size();
  vector<vector<int> > B(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      B[N - j - 1][i] = A[i][j];
    }
  }
  return B;
}

int main() {
  int N;
  cin >> N;
  vector<vector<int> > A(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A.at(i).at(j);
    }
  }
  vector<vector<int> > B(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> B.at(i).at(j);
    }
  }
  auto check = [&](const vector<vector<int> > &C) -> bool {
    bool ans = true;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (C[i][j] == 0) {
          continue;
        }
        if (B[i][j] == 0) {
          ans = false;
        }
      }
    }
    return ans;
  };
  bool ans = false;
  for (int i = 0; i < 4; i++) {
    if (check(A)) {
      ans = true;
    }
    vector<vector<int> > now = rot(A);
    A = now;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
