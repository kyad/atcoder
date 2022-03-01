// https://atcoder.jp/contests/abc241/tasks/abc241_c

#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> A) {
  int N = A.size();
  if (N < 6) {
    return false;
  }
  A.insert(A.begin(), 0);
  for (int n = 1; n <= N; n++) {
    A[n] += A[n - 1];
  }
  bool ans = false;
  for (int n = 6; n <= N; n++) {
    int count = A[n] - A[n - 6];
    if (count >= 4) {
      ans = true;
    }
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  bool ok = false;
  // yoko
  for (int y = 0; y < N; y++) {
    vector<int> A(N, 0);
    for (int x = 0; x < N; x++) {
      A[x] = (S[y][x] == '#' ? 1 : 0);
    }
    if (check(A)) {
      ok = true;
    }
  }
  // tate
  for (int x = 0; x < N; x++) {
    vector<int> A(N, 0);
    for (int y = 0; y < N; y++) {
      A[y] = (S[y][x] == '#' ? 1 : 0);
    }
    if (check(A)) {
      ok = true;
    }
  }
  // naname (1, 1)
  for (int x0 = 0; x0 < N; x0++) {
    vector<int> A;
    for (int n = 0; n < N; n++) {
      int x = x0 + n;
      int y = n;
      if (x >= N) {
        break;
      }
      A.push_back(S[y][x] == '#' ? 1 : 0);
    }
    if (check(A)) {
      ok = true;
    }
  }
  for (int y0 = 0; y0 < N; y0++) {
    vector<int> A;
    for (int n = 0; n < N; n++) {
      int x = n;
      int y = y0 + n;
      if (y >= N) {
        break;
      }
      A.push_back(S[y][x] == '#' ? 1 : 0);
    }
    if (check(A)) {
      ok = true;
    }
  }
  // naname (-1, 1)
  for (int x0 = 0; x0 < N; x0++) {
    vector<int> A;
    for (int n = 0; n < N; n++) {
      int x = x0 - n;
      int y = n;
      if (x < 0) {
        break;
      }
      A.push_back(S[y][x] == '#' ? 1 : 0);
    }
    if (check(A)) {
      ok = true;
    }
  }
  for (int y0 = 0; y0 < N; y0++) {
    vector<int> A;
    for (int n = 0; n < N; n++) {
      int x = N - 1 - n;
      int y = y0 + n;
      if (y >= N) {
        break;
      }
      A.push_back(S[y][x] == '#' ? 1 : 0);
    }
    if (check(A)) {
      ok = true;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}

