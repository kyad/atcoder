#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> C;
  for (int n = 0; n < N; n++) {
    int A, B;
    cin >> A >> B;
    C.push_back(B);
    C.push_back(A - B);
  }
  sort(C.rbegin(), C.rend());
  long long ans = 0;
  for (int i = 0; i < K; i++) {
    ans += C.at(i);
  }
  cout << ans << endl;
  return 0;
}
