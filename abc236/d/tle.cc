#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

pair<vector<int>, vector<int>> bit_to_vec(int N, int bit) {
  vector<int> A;
  vector<int> B;
  for (int n = 0; n < 2 * N; n++) {
    if ((bit >> n)& 1) { // selected
      A.push_back(n);
    } else {
      B.push_back(n);
    }
  }
  return make_pair(A, B);
}

int main() {
  int N;
  cin >> N;
  vector<vector<int> > A(2 * N, vector<int>(2 * N, 0));
  for (int i = 0; i < 2 * N; i++) {
    for (int j = i + 1; j < 2 * N; j++) {
      cin >> A[i][j];
    }
  }
  int ans = 0;
  for (int bit = 0; bit < (1<<(2 * N)); bit++) {
    pair<vector<int>, vector<int> > p = bit_to_vec(N, bit);
    if (p.first.size() != N) {
      continue;
    }
    do {
      int value = 0;
      for (int n = 0; n < N; n++) {
        int a = p.first[n];
        int b = p.second[n];
        int mn = min(a, b);
        int mx = max(a, b);
        value ^= A[mn][mx];
      }
      ans = max(ans, value);
    } while (next_permutation(p.second.begin(), p.second.end()));
  }
  cout << ans << endl;
  return 0;
}
