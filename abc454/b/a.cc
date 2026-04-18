#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> C(M, 0);
  for (int i = 0; i < N; i++) {
    int F;
    cin >> F;
    F--;
    C.at(F)++;
  }
  int mx = *max_element(C.begin(), C.end());
  if (mx == 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  int mn = *min_element(C.begin(), C.end());
  if (mn >= 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
