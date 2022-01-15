#include <iostream>
#include <map>
#include <vector>
using namespace std;

int digit(int n) {
  int ans = 1;
  while (n >= 10) {
    n /= 10;
    ans++;
  }
  return ans;
}

int g(int n) {
  if (n < 10) {
    return -1;
  }
  int top = n;
  int digit = 1;
  int temp = 1;
  while (top >= 10) {
    top /= 10;
    temp *= 10;
    digit++;
  }
  int ans = (n - top * temp) * 10 + top;
  temp = ans;
  for (int i = 0; i < digit - 1; i++) {
    temp /= 10;
  }
  if (temp == 0) {
    ans = -1;
  }
  return ans;
}
  
const int INF = 1000000000;
vector<int> dp;
int a;

int rec(int n) {
  if (dp[n] >= 0) {
    return dp[n];
  }
  dp[n] = INF;
  if (n % a == 0) {
    int next = rec(n / a);
    if (next < INF) {
      dp[n] = next + 1;
    }
  }
  int d = digit(n);
  int rotate = n;
  for (int i = 0; i < d - 1; i++) {
    rotate = g(rotate);
    if (rotate < 0) {
      break;
    }
    int next = rec(rotate);
    if (next < INF) {
      dp[n] = min(dp[n], next + i + 1);
    }
  }
  return dp[n];
}

int main() {
  int N;
  cin >> a >> N;
  dp.resize(1000001, -1);
  dp[1] = 0;
  for (int n = 2; n <= 1000000; n++) {
    rec(n);
  }
  int ans = dp[N];
  if (ans >= INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
