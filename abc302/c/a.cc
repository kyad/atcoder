#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int dist(string S, string T) {
  int ans = 0;
  assert(S.size() == T.size());
  int N = S.size();
  for (int n = 0; n < N; n++) {
    if (S[n] != T[n]) {
      ans++;
    }
  }
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  vector<int> a(N);
  for (int n = 0; n < N; n++) {
    a.at(n) = n;
  }
  bool ans = false;
  do {
    bool ok = true;
    for (int n = 0; n < N - 1; n++) {
      if (dist(S[a[n]], S[a[n + 1]]) != 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = true;
      break;
    }
  } while (next_permutation(a.begin(), a.end()));
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
