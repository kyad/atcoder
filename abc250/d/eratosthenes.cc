#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// int(sqrt(N))  O(log(N))
int int_sqrt(int N) {
  int left = 0;
  int right = N;
  while (right - left > 1) {
    int middle = (left + right) / 2;
    if (middle * middle >= N) {
      right = middle;
    } else {
      left = middle;
    }
  }
  if (right * right >= N) {
    return right;
  } else {
    return left;
  }
}

// Sieve of Eratosthenes  O(N * log log (N))
vector<bool> eratosthenes(int N) {
  vector<bool> is_prime(N + 1, true);
  is_prime.at(0) = false;
  if (N > 0) {
    is_prime.at(1) = false;
  }
  for (int k = 2; k < int_sqrt(N); k++) {
    for (int i = 2 * k; i <= N; i+=k) {
      is_prime.at(i) = false;
    }
  }
  return is_prime;
}

int main() {
  long long N;
  cin >> N;
  vector<bool> is_prime = eratosthenes(1000001);
  vector<long long> primes;
  vector<long long> neg_primes;
  map<long long, int> pos;
  for (int n = 1; n < 1000001; n++) {
    if (is_prime[n]) {
      pos[n] = (int)primes.size();
      primes.push_back(n);
      neg_primes.push_back(-n);
    }
  }
  sort(neg_primes.begin(), neg_primes.end());
  long long ans = 0;
  for (size_t j = 1; j < primes.size(); j++) {
    long long q = primes[j];
    long long q3 = q * q * q;
    long long L = N / q3;
    L = min(primes[j - 1], L);
    if (L < 2) {
      continue;
    }
    //vector<long long>::iterator it = lower_bound(primes.begin(), primes.end(), L);
    vector<long long>::iterator it = lower_bound(neg_primes.begin(), neg_primes.end(), -L);
    long long now = -(*it);
    int now_pos = pos[now];
    //cout << "q="<<q<< " now="<<now<< " pos="<<now_pos<<endl ;
    ans += (now_pos + 1);
  }
  cout << ans << endl;
  return 0;
}
