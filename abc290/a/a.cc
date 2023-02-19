#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  int ans = 0;
  for (int m = 0; m < M; m++) {
    int B;
    cin >> B;
    B--;
    ans += A.at(B);
  }
  cout << ans << endl;
  return 0;
}
