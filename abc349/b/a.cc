#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  vector<int> cnt(26, 0);
  for (int i = 0; i < N; i++) {
    cnt.at(S.at(i) - 'a')++;
  }
  vector<int> a(101, 0); // a[c]出現回数がc回の文字の種類数
  for (int j = 0; j < 26; j++) {
    int c = cnt.at(j);
    a.at(c)++;
  }
  bool ans = true;
  for (int i = 1; i <= 100; i++) {
    if (a.at(i) == 0 || a.at(i) == 2) {
      continue;
    }
    ans = false;
    break;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
