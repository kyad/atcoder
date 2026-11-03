#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = -1;
  int mx = -1;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    int area = A * B;
    if (area > mx) {
      mx = area;
      ans = i+ 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
