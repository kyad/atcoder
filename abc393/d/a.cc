#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<long long> p;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == '1') {
      p.push_back(i);
    }
  }
  int M = p.size();
  auto f = [&](int k) -> long long {
    // j=kより左
    long long left = 0;
    {
      long long sum = 0;
      for (int j = k - 1; j >= 0; j--) {
        sum += p.at(j + 1) - p.at(j) - 1;
        left += sum;
      }
    }
    // j=kより右
    long long right = 0;
    {
      long long sum = 0;
      for (int j = k + 1; j < M; j++) {
        sum += p.at(j) - p.at(j - 1) - 1;
        right += sum;
      }
    }
    long long ans = left + right;
    return ans;
  };
  long long ans;
  if (M % 2 == 1) {
    ans = f(M / 2);
  } else {
    ans = f(M / 2);
    if (M / 2 - 1 >= 0) {
      long long ans1 = f(M / 2 - 1);
      ans = min(ans, ans1);
    }
  }
  cout << ans << endl;
  return 0;
}
