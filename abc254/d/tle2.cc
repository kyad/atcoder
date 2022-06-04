// https://atcoder.jp/contests/abc254/tasks/abc254_d
// O(N sqrt(N)), TLE

#include <iostream>
#include <map>
#include <vector>
using namespace std;

// int(sqrt(n)) for n >= 0
const int INF = 200001;
int int_sqrt(int n) {
  if (n == 0) {
    return 0;
  }    
  int left = 0;
  int right = INF;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    long long y = (long long)mid * mid - n;
    if (y <= 0) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return left;
}

// O(sqrt(n))
inline vector<int> encode(int n) {
  int max = int_sqrt(n);
  vector<int> primes;
  for (int m = 2; m <= max; m++) {
    while (n % m == 0) {
      n /= m;
      primes.push_back(m);
    }
  }
  if (n != 1) {
    primes.push_back(n);
  }
  map<int, int> mp;
  for (size_t i = 0; i < primes.size(); i++) {
    mp[primes[i]]++;
  }
  vector<int> ans;
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    if (it->second % 2) {
      ans.push_back(it->first);
    }
  }
  return ans;
}

// Check if square, O(sqrt(n)), n >= 0
bool is_square(int n) {
  if (n == 0 || n == 1) {
    return true;
  }
  int m = int_sqrt(n) + 1;
  for (int i = 0; i < (int_sqrt(n) + 1); i++) {
    long long j = i;
    if (j * j == n) {
      return true;
    }
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  const int M = 200000;
  map<vector<int>, int> count;
  vector<long long> dp(M + 1, 0);
  int max = 0;
  for (int m = 1; m <= M; m++) {
    dp[m] = 1;
    if (m == 1) {
      continue;
    }
    vector<int> enc = encode(m);
    if ((int)enc.size() > max) {
      max = enc.size();
      cout << "max="<<max<<endl;
    }
    dp[m] += count[enc] * 2;
    count[enc]++;
    if (is_square(m)) { // (1, m), (m, 1)
      dp[m] += 2LL;
    }
  }
  long long ans = 0;
  for (int n = 2; n <= M; n++) {
    dp[n] += dp[n - 1];
  }
  cout << dp[N] << endl;
  return 0;
}
