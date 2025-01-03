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
  vector<int> len1(N, -1);  // '/'より左の1のレンの長さ
  int len = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == '/') {
      len1.at(i) = len;
      len = 0;
    } else if (S.at(i) == '1') {
      len++;
    } else {
      len = 0;
    }
  }
  vector<int> len2(N, -1);  // '/'より右の2のレンの長さ
  len = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (S.at(i) == '/') {
      len2.at(i) = len;
      len = 0;
    } else if (S.at(i) == '1') {
      len = 0;
    } else {
      len++;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (len1.at(i) == -1) {
      continue;
    }
    int now = min(len1.at(i), len2.at(i));
    ans = max(ans, now);
  }
  ans = ans * 2 + 1;
  cout << ans << endl;
  return 0;
}
