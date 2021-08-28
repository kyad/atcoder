// https://atcoder.jp/contests/typical90/tasks/typical90_a

#include <bits/stdc++.h>
using namespace std;

bool judge(vector<int> A, int K, int M) {
  int prev = 0;
  int sum = 0;
  int k = 0;
  for (size_t i = 0; i < A.size(); i++) {
    sum += (A.at(i) - prev);
    prev = A.at(i);
    if (sum >= M) {
      k++;
      sum = 0;
    }
  }
  return (k >= (K + 1));
}

int main() {
  int N, L, K;
  cin >> N >> L;
  cin >> K;
  vector<int> A(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  A.at(N) = L;

  int left = 1;
  int right = L / (K + 1) + 1;
  while (right - left > 1) {
    int mid = (right + left) / 2;
    if (judge(A, K, mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << left << endl;
  return 0;
}
