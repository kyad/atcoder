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
  for (int i = 0; i < N; i++) {
    int ans = -1;
    for (int j = i - 1; j >= 0; j--) {
      if (A.at(j) > A.at(i)) {
        ans = j + 1;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
