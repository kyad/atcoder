#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void naive(int N, const vector<string> &S) {
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int now = 0;
      for (int k = 0; k < (int)min(S[i].size(), S[j].size()); k++) {
        if (S[i][k] == S[j][k]) {
          now++;
        } else {
          break;
        }
      }
      ans += now;
    }
  }
  cout << ans << endl;
}

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  sort(S.begin(), S.end());
  naive(N, S);
  return 0;
}
