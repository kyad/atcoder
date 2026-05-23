#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int f(char c) {
  if (c <= 'c') {
    return 2;
  } else if (c <= 'f') {
    return 3;
  } else if (c <= 'i') {
    return 4;
  } else if (c <= 'l') {
    return 5;
  } else if (c <= 'o') {
    return 6;
  } else if (c <= 's') {
    return 7;
  } else if (c <= 'v') {
    return 8;
  } else if (c <= 'z') {
    return 9;
  }
  return 0;
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    int ans = f(S.at(0));
    cout << ans;
  }
  cout << endl;
  return 0;
}
