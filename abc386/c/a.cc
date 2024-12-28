#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool solve(string S, string T) {
  int N = S.size();
  int M = T.size();
  assert(N == M + 1);
  // N > Mの場合。
  int l = -1;  // 左から何文字まで当っているか
  for (int i = 0; i <= N - 2; i++) {
    if (S.at(i) == T.at(i)) {
      l++;
      continue;
    } else {
      break;
    }
  }
  // 後半
  for (int j = l + 1; j <= N - 2; j++) {
    if (S.at(j + 1) != T.at(j)) {
      return false;
    }
  }
  return true;
}

bool solve2(string S, string T) {
  int N = S.size();
  int M = T.size();
  assert(N == M);
  int l = -1;
  for (int i = 0; i <= N - 2; i++) {
    if (S.at(i) == T.at(i)) {
      l++;
      continue;
    } else {
      break;
    }
  }
  // 後半
  for (int j = l + 2; j <= N - 1; j++) {
    if (S.at(j) != T.at(j)) {
      return false;
    }
  }
  return true;
}

int main() {
  int K;
  string S, T;
  cin >> K >> S >> T;
  if (S == T) {
    cout << "Yes" << endl;
    return 0;
  }
  int N = S.size();
  int M = T.size();
  bool ans = false;
  if (N + 1 == M) {
    ans = solve(T, S);
  } else if (N == M) {
    ans = solve2(S, T);
  } else if (N == M + 1) {
    ans = solve(S, T);
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
