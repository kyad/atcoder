// https://atcoder.jp/contests/dp/tasks/dp_j

#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<vector<vector<double> > > dp;
int N;

double rec(int p, int q, int r) {
  if (dp[p][q][r] >= 0) {
    return dp[p][q][r];
  }
  int s = N - (p + q + r);
  double ans = 0;
  double denom = (1. - (double)s / N) * (1. - (double)s / N);
  if (p > 0) {
    ans += (double)p / (p + q + r) * rec(p - 1, q, r) + (double(p) / N / denom);
  }
  if (q > 0) {
    ans += (double)q / (p + q + r) * rec(p + 1, q - 1, r) + (double(q) / N / denom);
  }
  if (r > 0) {
    ans += (double)r / (p + q + r) * rec(p, q + 1, r - 1) + (double(r) / N / denom);
  }
  return dp[p][q][r] = ans;
}

int main() {
  cin >> N;
  map<int, int> count;
  for (int n = 0; n < N; n++) {
    int a;
    cin >> a;
    count[a]++;
  }
  dp.resize(N + 1, vector<vector<double> >(N + 1, vector<double>(N + 1, -1)));
  dp[0][0][0] = 0;
  cout << setprecision(15) << rec(count[1], count[2], count[3]) << endl;
  return 0;
}
