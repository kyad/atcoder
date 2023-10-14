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
  long long K;
  cin >> K;

  vector<long long> ns;

  for (int d = 1; d <= 10; d++) {
    int N = 10;
    int r = d;
    // next_combination(N, r)
    vector<int> mask(N, 1);
    for (int i = 0; i < N - r; i++) {
      mask.at(i) = 0;
    }
    do {
      long long M = 0;
      for (int i = N - 1; i >= 0; i--) {
        if (mask.at(i)) {
          // Do something
          M *= 10;
          M += i;
        }
      }
      if (M > 0) {
        ns.push_back(M);
      }
    } while (next_permutation(mask.begin(), mask.end()));
  }
  sort(ns.begin(), ns.end());
  long long ans = ns.at(K - 1);
  cout << ans << endl;
  return 0;
}
