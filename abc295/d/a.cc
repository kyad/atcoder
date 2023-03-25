#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int encode(vector<int> a) {
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    if (a.at(i) == 1) {
      ans += (1<<i);
    }
  }
  return ans;
}

long long f(long long n) {
  long long ans = n * (n - 1) / 2;
  return ans;
}

int main() {
  string S;
  cin >> S;
  int N = S.size();
  S.insert(S.begin(), '.');
  vector<vector<int> > sum(N + 1, vector<int>(10, 0));
  for (int n = 1; n <= N; n++) {
    int d = S[n] - '0';
    sum[n][d] = 1;
  }
  for (int n = 1; n <= N; n++) {
    for (int d = 0; d <= 9; d++) {
      sum[n][d] += sum[n - 1][d];
    }
  }
  for (int n = 1; n <= N; n++) {
    for (int d = 0; d <= 9; d++) {
      sum[n][d] %= 2;
    }
  }
  vector<int> count(1024, 0);
  for (int n = 0; n <= N; n++) {
    int value = encode(sum[n]);
    assert(0 <= value && value < 1024);
    count[value]++;
  }
  long long ans = 0;
  for (int i = 0; i < 1024; i++) {
    ans += f(count[i]);
  }
  cout << ans << endl;
  return 0;
}
