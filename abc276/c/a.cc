#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
  }
  int k;
  for (k = N - 2; k >= 0; k--) {
    if (P[k] > P[k + 1]) {
      break;
    }
  }
  assert(k >= 0);
  int l = -1;
  int M = 0;
  for (int i = k + 1; i < N; i++) {
    if (P[i] > P[k]) {
      continue;
    }
    if (P[i] > M) {
      l = i;
      M = P[i];
    }
  }
  assert(l >= 0);
  vector<int> a;
  a.push_back(P[k]);
  for (int i = k + 1; i < N; i++) {
    if (i == l) {
      continue;
    }
    a.push_back(P[i]);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  vector<int> Q(N);
  for (int i = 0; i < k; i++) {
    Q[i] = P[i];
  }
  Q[k] = M;
  for (int i = k + 1; i < N; i++) {
    Q[i] = a[i - (k + 1)];
  }
  for (int i = 0; i < N; i++) {
    cout << Q[i] << (i == N - 1 ? '\n' : ' ');
  }
  return 0;
}
