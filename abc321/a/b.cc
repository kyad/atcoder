#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool judge(int N) {
  vector<int> T;
  while (N > 0) {
    T.push_back(N % 10);
    N /= 10;
  }
  reverse(T.begin(), T.end());
  assert(T.size() >= 1);
  bool ans = true;
  int now = T[0];
  for (int n = 1; n < N; n++) {
    if (now >= 1 && T[n] <= now - 1) {
      now = T[n];
    } else {
      ans = false;
      break;
    }
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  bool ans = judge(N);
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
