#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// xをbase進数で見た時の桁数を返す
int digits(long long x, int base = 10) { int d = 0; while (x > 0) { x /= base; d++; } return d; }
long long connect(long long a, long long b) {
  int d = digits(b);
  for (int i = 0; i < d; i++) {
    a *= 10;
  }
  return a + b;
}

int main() {
  int N;
  cin >> N;
  int M = 10;
  long long MX = 1000000000;
  vector<vector<long long> > A(M + 1);
  for (int i = 0; i < 31; i++) {
    long long n = 1<<i;
    if (n > MX) {
      break;
    }
    int d = digits(n);
    A.at(d).push_back(n);
  }
  for (int d = 1; d <= M; d++) {  // 合計桁
    for (int a = 1; a < d; a++) {
      int b = d - a;
      for (long long p : A.at(a)) {
        for (long long q : A.at(b)) {
          long long r = connect(p, q);
          if (r <= MX) {
            A.at(d).push_back(r);
          }
        }
      }
    }
    sort(A.at(d).begin(), A.at(d).end());
    vector<long long>::iterator result = unique(A.at(d).begin(), A.at(d).end());
    A.at(d).erase(result, A.at(d).end());
  }
  vector<long long> B;
  for (int d = 1; d <= M; d++) {
    for (long long p : A.at(d)) {
      B.push_back(p);
    }
  }
  long long ans = B.at(N - 1);
  cout << ans << '\n';
  return 0;
}
