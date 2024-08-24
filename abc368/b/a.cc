#include <algorithm>
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
  }
  int ans = 0;
  while (true) {
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    int count = 0;
    for (int i = 0; i <= 1; i++) {
      if (A.at(i) > 0) {
        count++;
      }
    }
    if (count <= 1) {
      break;
    }
    // カウント
    ans++;
    // 操作
    for (int i = 0; i <= 1; i++) {
      A.at(i)--;
    }
  }
  cout << ans << endl;
  return 0;
}
