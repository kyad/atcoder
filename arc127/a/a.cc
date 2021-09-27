// https://atcoder.jp/contests/arc127/tasks/arc127_a

#include <iostream>
#include <map>
using namespace std;

// m^n, O(log n)
long long power(long long m, long long n, long long mod) {
  long long a = m;
  long long ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return ans;
}

int main() {
  const long long INF = 100000000000000000;
  long long N;
  cin >> N;
  // m = (start, (S, f))
  // Compute m so that ans = S + (N - start + 1) * f
  map<long long, pair<long long, int> > m;
  m[0] = make_pair(0LL, 0);
  long long S = 0;
  for (int d = 1; d <= 16; d++) {
    long long start = power(10, d - 1, INF);
    long long width = power(10, d - 2, INF);
    int f = 1;
    for (int i = 0; i < d - 1; i++) {
      m[start] = make_pair(S, f);
      start += width;
      S += f * width;
      f++;
      width /= 10;
    }
    m[start] = make_pair(S, f);
    start++;
    S += f;
    f--;
    width = 8;
    for (int i = 0; i < d; i++) {
      m[start] = make_pair(S, f);
      start += width;
      S += f * width;
      f--;
      width *= 10;
    }
  }
  map<long long, pair<long long, int> >::iterator it = m.upper_bound(N);
  it--;
  long long start = it->first;
  S = it->second.first;
  int f = it->second.second;
  cout << S + (N - start + 1) * f << endl;
  return 0;
}
