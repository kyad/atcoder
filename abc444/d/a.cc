#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  int M = 200000;
  vector<int> c(M + 10, 0);
  for (int i = 0; i < N; i++) {
    c.at(0)++;
    c.at(A.at(i))--;
  }
  for (int i = 1; i < M + 10; i++) {
    c.at(i) += c.at(i - 1);
  }
  // 繰り上げの処理
  vector<int> d(M + 10, 0);  // 確定
  for (int i = 0; i < M + 10; i++) {
    d.at(i) = c.at(i) % 10;
    // carry
    int k = 1;
    while (c.at(i) > 0) {
      c.at(i) /= 10;
      c.at(i + k) += c.at(i) % 10;
      k++;
    }
  }
  bool first_zero = true;
  for (int i = M + 9; i >= 0; i--) {
    if (first_zero && d.at(i) == 0) {
      continue;
    }
    first_zero = false;
    cout << d.at(i);
  }
  cout << '\n';
  return 0;
}
