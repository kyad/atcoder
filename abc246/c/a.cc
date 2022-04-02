#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K, X;
  cin >> N >> K >> X;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
    int k = A.at(n) / X;
    k = min(K, k);
    K -= k;
    A.at(n) -= (X * k);
  }
  vector<pair<long long, long long> > B(N);
  for (int n = 0; n < N; n++) {
    long long r = A.at(n) % X;
    B.at(n) = make_pair(r, A.at(n));
  }
  sort(B.begin(), B.end(), greater<pair<int, int> >());
  long long ans = 0;
  for (int n = 0; n < N; n++) {
    long long a = B[n].second;
    if (K > 0) {
      int r = a % X;
      K--;
      a -= r;
    }
    ans += (long long)a;
  }
  cout << ans << endl;
  return 0;
}
