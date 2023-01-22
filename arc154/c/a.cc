#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void testcase() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  for (int n = 0; n < N; n++) {
    cin >> B.at(n);
  }

  vector<int> T;
  int now = B[0];
  T.push_back(now);
  for (int n = 0; n < N; n++) {
    if (B[(n + 1) % N] != now) {
      now = B[(n + 1) % N];
      T.push_back(now);
    }
  }
  if (now == B[0] && T.size() != 1) {
    T.pop_back();
  }
  int M = T.size();
  if (M == N) {
    bool ans = (A == B);
    cout << (ans ? "Yes" : "No") << '\n';
    return;
  }

  auto f = [&](int start) -> bool {
    int l = 0;
    for (int i = 0; i < N; i++) {
      if (A[(start + i) % N] == T[l]) {
        l++;
      }
      if (l >= M) {
        break;
      }
    }
    return (l == M);
  };

  int ans = false;
  for (int start = 0; start < N; start++) {
    if (f(start)) {
      ans = true;
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    testcase();
  }
  return 0;
}
