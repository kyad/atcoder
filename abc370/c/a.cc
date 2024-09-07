#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  string T;
  cin >> S >> T;
  int N = S.size();
  vector<string> X;
  for (int t = 0; t < N; t++) {
    int count = 0;  // 違う個数
    vector<string> A;
    for (int i = 0; i < N; i++) {
      if (S.at(i) != T.at(i)){
        string SS(S);
        SS.at(i) = T.at(i);
        A.push_back(SS);
        count++;
      }
    }
    if (count == 0) {
      break;
    }
    sort(A.begin(), A.end());
    X.push_back(A.at(0));
    S = A.at(0);
  }
  int M = X.size();
  cout << M << endl;
  for (int j = 0; j < M; j++) {
    cout << X.at(j) << endl;
  }
  return 0;
}
