#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  int vacant = K;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (vacant >= A.at(i)) {
      vacant -= A.at(i);
    } else {
      ans++; // 前をスタートさせる      
      vacant = K - A.at(i);
    }
  }
  if (vacant < K) {
    ans++;
  }
  cout << ans << endl;
  return 0;
}
