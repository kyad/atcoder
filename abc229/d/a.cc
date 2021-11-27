#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int K;
  cin >> K;
  int N = (int)S.size();
  vector<int> sum(N + 1, 0);  // 1-indexed
  for (int n = 1; n <= N; n++) {
    if (S[n - 1] == '.') {
      sum[n] = sum[n - 1] + 1;
    } else {
      sum[n] = sum[n - 1];
    }
  }
  int left = 0;  // OK
  int right = 200001;  // NG
  while (right - left > 1) {
    int mid = (left + right) / 2;
    bool ok = false;
    for (int n = 1; n <= N - mid + 1; n++) {
      int temp = sum[n + mid - 1] - sum[n - 1];
      if (temp <= K) {
        ok = true;
        break;
      }
    }
    if (ok) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << left << endl;
  return 0;
}
