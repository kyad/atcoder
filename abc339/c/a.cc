#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long sum = 0;
  long long mn = 0;
  for (int n = 0; n < N; n++) {
    long long A;
    cin >> A;
    sum += A;
    mn = min(mn, sum);
  }
  long long ans = sum - mn;
  cout << ans << endl;
  return 0;
}
