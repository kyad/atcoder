#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


int f(int N) {
  int ans = 0;
  while (N > 0) {
    int a = N % 10;
    ans += (a * a);
    N /= 10;
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < 10000; i++) {
    N = f(N);
    if (N == 1) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << '\n';
  return 0;
}
