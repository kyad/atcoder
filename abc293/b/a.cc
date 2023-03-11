#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
    A.at(n)--;
  }
  vector<bool> called(N, false);
  for (int n = 0; n < N; n++) {
    if (!called.at(n)) {
      called.at(A.at(n)) = true;
    }
  }
  vector<int> X;
  for (int n = 0; n < N; n++) {
    if (!called.at(n)) {
      X.push_back(n);
    }
  }
  int K = X.size();
  cout << K << endl;
  for (int k = 0; k < K; k++) {
    cout << (X[k] + 1) << " \n"[k == K - 1];
  }
  return 0;
}
