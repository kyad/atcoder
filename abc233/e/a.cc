// https://atcoder.jp/contests/abc233/tasks/abc233_e

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string X;
  cin >> X;
  vector<int> A;
  for (size_t n = 0; n < X.size(); n++) {
    A.push_back(X[n] - '0');
  }
  vector<int> S;
  S.push_back(A[0]);  // S[0] = A[0];
  for (size_t n = 1; n < A.size(); n++) {
    S.push_back(S[n - 1] + A[n]);  // S[n] = S[n - 1] + A[n];
  }
  reverse(S.begin(), S.end());
  int N = (int)S.size();
  int n = 0;
  while (n < N) {
    if (S[n] <= 9) {
      n++;
      continue;
    }
    if (n < N - 1) {
      S[n + 1] += S[n] / 10;
    } else {
      S.push_back(S[n] / 10);
      N++;
    }
    S[n] = S[n] % 10;
    n++;
  }
  reverse(S.begin(), S.end());
  for (int n = 0; n < N; n++) {
    char c = '0' + S[n];
    cout << c;
  }
  cout << endl;
  return 0;
}
