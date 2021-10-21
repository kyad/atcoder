// https://atcoder.jp/contests/abc223/tasks/abc223_e

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool solve0(int W, int H, long long A, long long B, long long C) {
  long long a = (A + (W - 1)) / W;
  long long b = (B + (W - 1)) / W;
  long long c = (C + (W - 1)) / W;
  return (a + b + c) <= H;
}

bool solve1(int W, int H, long long A, long long B, long long C) {
  long long h = (long long)H - (A + (W - 1)) / W;
  if (h <= 0) {
    return false;
  }
  long long b = (B + (h - 1)) / h;
  long long c = (C + (h - 1)) / h;
  return (b + c) <= W;
}

int main() {
  int X, Y;
  vector<long long> array(3);
  cin >> X >> Y >> array.at(0) >> array.at(1) >> array.at(2);
  sort(array.begin(), array.end());
  string ans = "No";
  do {
    if (solve0(X, Y, array[0], array[1], array[2])) {
      ans = "Yes";
      break;
    } else if (solve0(Y, X, array[0], array[1], array[2])) {
      ans = "Yes";
      break;
    } else if (solve1(X, Y, array[0], array[1], array[2])) {
      ans = "Yes";
      break;
    } else if (solve1(Y, X, array[0], array[1], array[2])) {
      ans = "Yes";
      break;
    }
  } while (next_permutation(array.begin(), array.end()));
  cout << ans << endl;
  return 0;
}
