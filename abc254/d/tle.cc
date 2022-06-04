#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

// int(sqrt(n)) for n >= 0
const int INF = 100000;
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
vector<int> prime_factorization(int n) {
  int max = int_sqrt(n);
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
  int N;
  //const int M = 200000;
  //const int M = 30;
  const int M = 30;
  vector<long long> dp(M + 1, 0);
  for (int m = 1; m <= M; m++) {
    dp[m] = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= m; j++) {
        vector<int> primes = prime_factorization(i * j);
        map<int, int> mp;
        for (size_t i = 0; i < primes.size(); i++) {
          mp[primes[i]]++;
        }
        bool ok = true;
        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
          if (it->second % 2 == 1) {
            ok = false;
          }
        }
        if (ok) {
          dp[m]++;
        }
      }
    }
  }
  for (int n = 1; n <= M; n++) {
    cout << "dp["<<n<<"]="<<dp[n]<<endl;;
  }
  return 0;
}
