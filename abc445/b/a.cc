#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  int m = -1;
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
    m = max(m, (int)S.at(i).size());
  }
  for (int i = 0; i < N; i++) {
    int add = (m - (int)S.at(i).size()) / 2;
    string T;
    for (int j = 0; j < add; j++) {
      T.push_back('.');
    }
    T += S.at(i);
    for (int j = 0; j < add; j++) {
      T.push_back('.');
    }
    cout << T << '\n';
  }
  return 0;
}
