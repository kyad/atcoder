#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  S.push_back('#');
  int N = S.size();
  for (int i = 1; i < N; i++) {
    if (S.at(i) == '#') {
      if (S.at(i - 1) == '.') {
        S.at(i - 1) = 'o';
      }
    }
  }
  S.pop_back();
  cout << S << endl;
  return 0;
}
