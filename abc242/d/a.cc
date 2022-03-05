// https://atcoder.jp/contests/abc242/tasks/abc242_d

#include <iostream>
#include <vector>
using namespace std;

string S;

int f(long long t, long long l) {
  int ans;
  if (t == 0) {
    ans = S[l] - 'A';
    return ans;
  }
  if (l == 0) {
    ans = S[0] - 'A' + (int)(t % 3);
    ans %= 3;
    return ans;
  }
  ans = f(t - 1, l / 2);
  if (l % 2 == 0) {
    ans += 1;
  } else {
    ans += 2;
  }
  ans %= 3;
  return ans;
}

int main() {
  cin >> S;
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    long long t, k;
    cin >> t >> k;
    long long l = k - 1;
    int ans = f(t, l);
    char c = 'A' + ans;
    cout << c << endl;
  }
  return 0;
}
