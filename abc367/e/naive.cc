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
  int N;
  long long K;
  cin >> N >> K;
  vector<int> X(N), A(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i);
    X.at(i)--;
  }
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  // Update A once
  auto f = [&]() {
    vector<int> prev(A);
    for (int i = 0; i < N; i++) {
      A.at(i) = prev.at(X.at(i));
    }
  };

  // naive
  for (int k = 0; k < K; k++) {
    f();
  }
  dumpvec(A);
  return 0;
}
