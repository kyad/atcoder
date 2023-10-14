#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

bool check1(const string& S, const string& T) {
  int M = S.size();
  int L = T.size();
  if (M != L) {
    return false;
  }
  for (int i = 0; i < M; i++) {
    if (S.at(i) != T.at(i)) {
      return false;
    }
  }
  return true;
}

bool check2(const string& S, const string& T) {
  int M = S.size();
  int L = T.size();
  if (M != L + 1) {
    return false;
  }
  int i = 0;
  int j = 0;
  int error = 0;
  while (j < L) {
    if (S.at(i) == T.at(j)) {
      i++;
      j++;
    } else {
      if (error >= 1) {
        return false;
      }
      assert(i < M);
      i++;
      error++;
    }
  }
  return true;
}

bool check4(const string& S, const string& T) {
  int M = S.size();
  int L = T.size();
  if (M != L) {
    return false;
  }
  int i = 0;
  int j = 0;
  int error = 0;
  while (j < L) {
    if (S.at(i) == T.at(j)) {
    } else {
      if (error >= 1) {
        return false;
      }
      error++;
    }
    i++;
    j++;
  }
  return true;
}



bool solve(const string& S, const string& T) {
  // 1
  if (check1(S, T)) {
    return true;
  }
  // 2
  if (check2(S, T)) {
    return true;
  }
  // 3
  if (check2(T, S)) {
    return true;
  }
  // 4
  if (check4(S, T)) {
    return true;
  }
  return false;
}

int main() {
  int N;
  string T;
  cin >> N >> T;
  vector<int> ans;
  for (int n = 0; n < N; n++) {
    string S;
    cin >> S;
    if (solve(S, T)) {
      ans.push_back(n + 1);
    }
  }
  sort(ans.begin(), ans.end());
  int K = ans.size();
  cout << K << endl;
  for (int n = 0; n < K; n++) {
    cout << ans.at(n);
    if (n + 1 != K) {
      cout << ' ';
    }
  }
  cout << endl;
  return 0;
}
