#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int> > LR(N);
  for (int n = 0; n < N; n++) {
    cin >> LR.at(n).first >> LR.at(n).second;
  }
  sort(LR.begin(), LR.end());
  int left = LR.at(0).first;
  int right = LR.at(0).second;
  for (int n = 1; n < N; n++) {
    int L = LR.at(n).first;
    int R = LR.at(n).second;
    if (L <= right) {
      // concat
      right = max(right, R);
    } else {
      cout << left << ' ' << right << endl;
      left = L;
      right = R;
    }
  }
  cout << left << ' ' << right << endl;
  return 0;
}
