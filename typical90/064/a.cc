#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<long long> D(N - 1);
  for (int n = 0; n < N - 1; n++) {
    D[n] = A[n + 1] - A[n];
  }
  long long S = 0;
  for (int n = 0; n < N - 1; n++) {
    S += abs(D[n]);
  }
  for (int qi = 0; qi < Q; qi++) {
    int L, R;
    long long V;
    cin >> L >> R >> V;
    L--; R--;
    if (L >= 1) {
      S -= abs(D[L - 1]);
      D[L - 1] += V;
      S += abs(D[L - 1]);
    }
    if (R <= N - 2) {
      S -= abs(D[R]);
      D[R] -= V;
      S += abs(D[R]);
    }
    cout << S << endl;
  }
  return 0;
}
