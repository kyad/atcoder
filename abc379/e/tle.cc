#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  multiprecision::cpp_int ans = 0;
  multiprecision::cpp_int prev = 0;
  for (int i = 0; i < N; i++) {
    int d = S.at(i) - '0';
    multiprecision::cpp_int now = prev * 10;
    now += d * (i + 1);
    prev = now;
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
