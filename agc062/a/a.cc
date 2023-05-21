#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void testcase() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  if (S[0] != 'B') {
    cout << 'A' << endl;
    return;
  }
  char now = 'B';
  for (int n = 0; n < N; n++) {
    if (S[n] == now) {
      continue;
    }
    now = S[n];
    if (now == 'B') {
      cout << 'A' << endl;
      return;
    }
  }
  cout << 'B' << endl;
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    testcase();
  }
  return 0;
}
