#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 4e18;

int main() {
  int N;
  cin >> N;
  vector<long long> K(N);
  for (int i = 0; i < N; i++) {
    cin >> K.at(i);
  }
  long long ans = INF;
  int N2 = 1<<N;
  for (int bit = 0; bit < N2; bit++) {
    long long A = 0;
    long long B = 0;
    for (int i = 0; i < N; i++) {
      if (bit>>i&1) {
        A += K.at(i);
      } else {
        B += K.at(i);
      }
    }
    long long now = max(A, B);
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
