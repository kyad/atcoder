#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

int main() {
  int N, K, X;
  cin >> N >> K >> X;
  vector<int> B;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    B.push_back(A);
    if (i + 1 == K) {
      B.push_back(X);
    }
  }
  dumpvec(B);
  return 0;
}
