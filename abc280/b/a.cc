#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> S(N, 0);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  vector<int> A(N, 0);
  A.at(0) = S.at(0);
  for (int n = 1; n < N; n++) {
    A.at(n) = S.at(n) - S.at(n - 1);
  }
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << (n == N - 1 ? '\n' : ' ');
  }
  return 0;
}
