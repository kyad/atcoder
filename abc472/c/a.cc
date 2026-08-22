#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  long long K;
  cin >> N >> M >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<bool> B(N, false);
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    if (i >= M) {
      int j = i - M;
      if (B.at(j) == true) {
        sum -= A.at(j);
      }
    }
    long long nsum = sum;
    nsum += A.at(i);
    if (nsum <= K) {
      B.at(i) = true;
      sum = nsum;
    } else {
      B.at(i) = false;
    }
  }
  for (int i = 0; i < N; i++) {
    bool ans = B.at(i);
    cout << (ans ? "Yes" : "No") << '\n';
  }
  return 0;
}
