#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > ans(N);
  for (int i = 0; i < N; i++) {
    int K;
    cin >> K;
    for (int k = 0; k < K; k++) {
      int A;
      cin >> A;
      A--;
      ans.at(A).push_back(i);
    }
  }
  for (int i = 0; i < N; i++) {
    int  X = ans.at(i).size();
    cout << X;
    for (int j : ans.at(i)) {
       cout << ' ' << (j+1);
     }
     cout << endl;
   }
  return 0;
}

