#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  string S;
  cin >> S;
  string T;
  cin >> T;
  queue<char> q;
  for (char c : S) {
    q.push(c);
  }
  int i = 0;
  vector<int> A;
  while (!q.empty()) {
    char c = q.front();
    if (T.at(i) == c) {
      A.push_back(i + 1);
      q.pop();
    }
    i++;
  }
  dump(A);
  return 0;
}
