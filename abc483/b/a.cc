#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> X(N);
  for (int i = 0; i < N; i++) {
    X.at(i) = i + 1;
  }
  for (int qi = 0; qi < Q; qi++) {
    int K;
    cin >> K;
    vector<int> nX(X);
    for (int i = 0; i < K; i++) {
      nX.at(i) = -X.at(K - i - 1);
    }
    swap(X, nX);
  }
  for (int i = 0; i < N; i++) {
    cout << X.at(i) << '\n';
  }
  return 0;
}
