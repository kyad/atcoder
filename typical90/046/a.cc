#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<long long> > count(3, vector<long long>(46, 0));
  for (int i = 0; i < 3; i++) {
    for (int n = 0; n < N; n++) {
      int A;
      cin >> A;
      count[i][A % 46]++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < 46; i++) {
    for (int j = 0; j < 46; j++) {
      for (int k = 0; k < 46; k++) {
        if ((i + j + k) % 46 == 0) {
          ans += count[0][i] * count[1][j] * count[2][k];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
