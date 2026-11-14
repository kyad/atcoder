#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int K;
  cin >> K;
  vector<int> A(K);
  int nine = false;
  for (int i = 0; i < K; i++) {
    cin >> A.at(i);
    if (A.at(i) == 9) {
      nine = true;
    }
  }
  int ans = -1;
  if (nine) {
    ans = *min_element(A.begin(), A.end());

  }
  cout << ans << '\n';
  return 0;
}
