#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool> > a(N, vector<bool>(N, false));
  for (int m = 0; m < M; m++) {
    int K;
    cin >> K;
    vector<int> X(K);
    for (int k = 0; k < K; k++) {
      cin >> X.at(k);
      X.at(k)--;
    }
    for (int i = 0; i < K; i++) {
      for (int j = i + 1; j < K; j++) {
        a[X[i]][X[j]] = true;
        a[X[j]][X[i]] = true;
      }
    }
  }
  bool ans = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) {
        continue;
      }
      if (a[i][j] == false) {
        ans = false;
      }
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
