#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void testcase() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  char c = S[0];
  // 1
  for (int i = 1; i < N; i++) {
    if (S[i] > c) {
      cout << "Yes" << endl;
      return;
    }
  }
  // 2
  for (int i = 1; i < N; i++) {
    if (S[i] == c) {
      string P = S.substr(0, i);
      string Q = S.substr(i, N - i);
      if (P < Q) {
        cout << "Yes" << endl;
        return;
      }
    }
  }
  cout << "No" << endl;
  return;
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    testcase();
  }
  return 0;
}
