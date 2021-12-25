#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<long long> S(N);
  S[0] = A[0];
  for (int n = 1; n < N; n++) {
    S.at(n) = S.at(n - 1) + A.at(n);
  }
  map<long long, long long> mp;
  long long ans = 0;
  for (int n = N - 1; n >= 0; n--) {
    if (mp.count(S[n] + K) > 0) {
      ans += mp[S[n] + K];
    }
    mp[S[n]]++;
  }
  ans += mp[K];
  cout << ans << endl;
  return 0;
}
