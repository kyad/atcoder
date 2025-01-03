#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<int> count(26, 0);
  int N = S.size();
  if (N % 2 != 0) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < N / 2; i++) {
    if (S.at(2 * i) != S.at(2 * i + 1)) {
      cout << "No" << endl;
      return 0;
    }
    count.at(S.at(2 * i) - 'a') += 2;
  }
  for (int i = 0; i < 26; i++) {
    if (count.at(i) != 0 && count.at(i) != 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
