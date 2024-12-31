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
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
  }
  B.at(N - 1) = 0;
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int x = -1;
  int j = N - 1;
  for (int i = N - 1; i >= 0; i--) {
    if (B.at(j) >= A.at(i)) {
      j--;
    } else {
      if (x >= 0) {
        cout << -1 << endl;
        return 0;
      }
      x = A.at(i);
    }
  }
  cout << x << endl;
  return 0;
}
