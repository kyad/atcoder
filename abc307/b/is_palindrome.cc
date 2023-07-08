#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool is_palindrome(string S) {
  int N = S.size();
  for (int l = 0; l < N / 2; l++) {
    int r = N - 1 - l;
    if (S.at(l) != S.at(r)) {
      return false;
    }
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) {
        continue;
      }
      string T = S[i] + S[j];
      if (is_palindrome(T)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
