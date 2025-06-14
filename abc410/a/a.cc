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
  int K;
  cin >> K;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (K <= A.at(i)) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
