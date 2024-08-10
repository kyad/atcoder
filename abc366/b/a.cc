#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  int M = 0;
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
    M = max(M, (int)S.at(i).size());
  }
  vector<string> T(M, string(N, '*'));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < (int)S.at(i).size(); j++) {
      T.at(j).at(N - i - 1) = S.at(i).at(j);
    }
  }
  for (int j = 0; j < M; j++) {
    while (T.at(j).back() == '*') {
      T.at(j).pop_back();
    }
  }
  for (int j = 0; j < M; j++) {
    cout << T.at(j) << '\n';
  }
  return 0;
}
