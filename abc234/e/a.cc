#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool is_tousa(int x) {
  if (x <= 99) {
    return true;
  }
  int d0 = x % 10;
  x /= 10;
  int d1 = x % 10;
  x /= 10;
  int delta = d1 - d0;
  int prev = d1;
  while (x > 0) {
    int d = x % 10;
    if (d - prev != delta) {
      return false;
    }
    prev = d;
    x /= 10;
  }
  return true;
}

long long gen_value(int digits, int top, int delta) {
  long long ans = 0;
  for (int d = 0; d < digits; d++) {
    ans += top;
    if (d == digits - 1) {
      break;
    }
    ans *= 10;
    top += delta;
  }
  return ans;
}

int main() {
  vector<long long> tousa;
  for (int n = 1; n <= 99999; n++) {
    if (is_tousa(n)) {
      tousa.push_back(n);
    }
  }
  for (int digits = 6; digits <= 10; digits++) {
    for (int top = 1; top <= 9; top++) {
      tousa.push_back(gen_value(digits, top, 0));
    }
    for (int top = 1; top <= 10 - digits; top++) {
      tousa.push_back(gen_value(digits, top, 1));
    }
    for (int top = 9; top >= digits - 1; top--) {
      tousa.push_back(gen_value(digits, top, -1));
    }
  }
  for (int digits = 11; digits <= 17; digits++) {
    for (int top = 1; top <= 9; top++) {
      tousa.push_back(gen_value(digits, top, 0));
    }
  }
  tousa.push_back(gen_value(18, 1, 0));
  sort(tousa.begin(), tousa.end());
  long long X;
  cin >> X;
  cout << *lower_bound(tousa.begin(), tousa.end(), X) << endl;
  return 0;
}
