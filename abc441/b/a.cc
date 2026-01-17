#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  string T;
  cin >> T;
  vector<int> A(26, 0);
  for (int i = 0; i < N; i++) {
    int a = S.at(i) - 'a';
    A.at(a) = 1;
  }
  for (int j = 0; j < M; j++) {
    int a = T.at(j) - 'a';
    if (A.at(a) == 1) {
      A.at(a) = 3;
    } else {
      A.at(a) = 2;
    }
  }
  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    string W;
    cin >> W;
    vector<int> count(4, 0);
    for (char c : W) {
      int a = c - 'a';
      count.at(A.at(a))++;
    }
    string ans = "Unknown";
    if (count.at(1) >= 1 && count.at(2) == 0 && count.at(0) == 0) {
      ans = "Takahashi";
    } else if (count.at(2) >= 1 && count.at(1) == 0 && count.at(0) == 0) {
      ans = "Aoki";
    }
    cout << ans << '\n';
  }
  return 0;
}
