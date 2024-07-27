#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long X, Y;
  cin >> N >> X >> Y;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<long long> B(N);
  for (int n = 0; n < N; n++) {
    cin >> B.at(n);
  }
  auto f = [&](vector<long long> A, long long X) {
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    int ans = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
      if (sum > X) {
        break;
      }
      sum += A.at(i);
      ans++;
    }
    return ans;
  };
  int a = f(A, X);
  int b = f(B, Y);
  int ans = min(a, b);
  cout << ans << endl;
  return 0;
}
