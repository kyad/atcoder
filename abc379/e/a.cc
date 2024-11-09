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
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += (long long)(i + 1) * (S.at(i) - '0');
  }
  // 筆算
  vector<int> ds;
  long long carry = 0;
  for (int i = N - 1; i >= 0; i--) {
    long long now = sum + carry;
    ds.push_back(now % 10);
    carry = now / 10;
    sum -= (long long)(i + 1) * (S.at(i) - '0');
  }
  if (carry != 0) {
    cout << carry;
  }
  reverse(ds.begin(), ds.end());
  for (int d : ds) {
    cout << d;
  }
  cout << endl;
  return 0;
}
