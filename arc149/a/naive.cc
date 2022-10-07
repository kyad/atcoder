#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost;


int solve(int N, int M, int d) {
  string s;
  for (int n = 0; n < N; n++) {
    s.push_back('0' + d);
  }
  multiprecision::cpp_int X(s);
  int ans = -1;
  for (int n = 0; n < N; n++) {
    if (X % M == 0) {
      ans = N - n;
      break;
    }
    X /= 10;
  }
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  int ans_len = -1;
  int ans_d = -1;
  for (int d = 9; d >= 1; d--) {
    int now = solve(N, M, d);
    if (now > ans_len) {
      ans_len = now;
      ans_d = d;
    }
  }
  if (ans_len < 0) {
    cout << ans_len << endl;
  } else {
    for (int i = 0; i < ans_len; i++) {
      cout << ans_d;
    }
    cout << endl;
  }
  return 0;
}
