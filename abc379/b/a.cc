#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  auto f = [&]() {
    int len = 0;
    for (int i = 0; i < N; i++) {
      if (S.at(i) == 'O') {
        len++;
        if (len == K) {
          int start = i - len + 1;
          for (int j = start; j <= i; j++) {
            S.at(j) = 'X';
          }
          return true;
        }
      } else {
        len = 0;
      }
    }
    return false;
  };
  int ans = 0;
  while (f()) {
    ans++;
  }

  cout << ans << endl;
  return 0;
}
