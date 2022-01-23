#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

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

  // next_combination
  vector<bool> mask(2 * N, false);
  fill(mask.end() - N, mask.end(), true);
  do {
    pair<vector<int>, vector<int> > p;
    for (int i = 0; i < 2 * N; i++) {
      if (mask[i]) {
        p.first.push_back(i);
      } else {
        p.second.push_back(i);
      }
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
  } while (next_permutation(mask.begin(), mask.end()));
  cout << ans << endl;
  return 0;
}
