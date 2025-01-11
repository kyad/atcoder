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
  // K組作れるか？
  auto check = [&](int K) -> bool {
    vector<int> left(K), right(K);
    for (int i = 0; i < K; i++) {
      left.at(i) = A.at(i);
    }
    for (int i = 0; i < K; i++) {
      right.at(i) = A.at(N - K + i);
    }
    bool ans = true;
    for (int i = 0; i < K; i++) {
      if (left.at(i) * 2 > right.at(i)) {
        ans = false;
        break;
      }
    }
    return ans;
  };
  int left = 0;  // OK
  int right = N / 2 + 1;  // NG
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (check(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  int ans = left;
  cout << ans << endl;
  return 0;
}
