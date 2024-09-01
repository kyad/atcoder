#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<int> A;
vector<int> R;
int N, K;

void dump(const vector<int> &A) {
  int N = A.size();
  for (int i = 0; i < N; i++) {
    cout << A[i] << " \n"[i == N - 1];
  }
}

// n文字目以降を列挙する
void f(int n) {
  if (n == N) {  // 終了条件
    int sum = 0;
    for (int i = 0; i < N; i++) {
      sum += A[i];
    }
    if (sum % K == 0) {
      dump(A);
    }
    return;
  }

  for (int r = 1; r <= R[n]; r++) {
    A[n] = r;
    f(n + 1);
  }
}

int main() {
  cin >> N >> K;
  R.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> R.at(i);
  }
  A.resize(N);
  f(0);
  return 0;
}
