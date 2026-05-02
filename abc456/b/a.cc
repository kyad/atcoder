#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
  vector<vector<int>> A(3, vector<int>(6));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> A.at(i).at(j);
    }
  }
  vector<vector<int>> count(3, vector<int>(7, 0));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      int a = A.at(i).at(j);
      count.at(i).at(a)++;
    }
  }
  auto f = [&](int a, int b, int c) {
    double A = (double)count.at(0).at(a) / 6;
    double B = (double)count.at(1).at(b) / 6;
    double C = (double)count.at(2).at(c) / 6;
    double ans = A * B * C;
    return ans;
  };
  double ans = 0;
  ans += f(4, 5, 6);
  ans += f(4, 6, 5);
  ans += f(5, 4, 6);
  ans += f(6, 4, 5);
  ans += f(5, 6, 4);
  ans += f(6, 5, 4);
  cout << setprecision(16) << ans << '\n';
  return 0;
}
