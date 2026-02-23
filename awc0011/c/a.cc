#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  unsigned long long K;
  cin >> N >> K;
  vector<unsigned long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  unsigned long long sum = 0;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if ((A.at(i) | K) == K) {
      ans++;
      sum |= A.at(i);
    }
  }
  if (sum != K) {
    ans = -1;
  }
  if (ans == 0) {
    ans = -1;
  }
  cout << ans << '\n';
  return 0;
}
