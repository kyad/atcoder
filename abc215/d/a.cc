#include <bits/stdc++.h>
using namespace std;

vector<int> prime_factorization(int n) {
  int max = (int)sqrt(n);
  vector<int> ans;
  for (int m = 2; m <= max; m++) {
    while (n % m == 0) {
      n /= m;
      ans.push_back(m);
    }
  }
  if (n != 1) {
    ans.push_back(n);
  }
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  set<int> S;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A[n];
  }
  for (int n = 0; n < N; n++) {
    vector<int> primes = prime_factorization(A[n]);
    for (size_t i = 0; i < primes.size(); i++) {
      S.insert(primes[i]);
    }
  }
  vector<bool> list(M + 1, true);
  for (auto prime : S) {
    if (prime == 1) {
      continue;
    }
    if (prime > M) {
      continue;
    }
    int p = prime;
    while (true) {
      list[p] = false;
      p += prime;
      if (p > M) {
        break;
      }
    }
  }
  int count = 0;
  for (int m = 1; m <= M; m++) {
    if (list[m]) {
      count++;
    }
  }
  cout << count << endl;
  for (int m = 1; m <= M; m++) {
    if (list[m]) {
      cout << m << endl;
    }
  }
  return 0;
}
