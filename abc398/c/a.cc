#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    int a = A.at(i);
    mp[a]++;
  }
  int a = -1;
  for (auto it = mp.rbegin(); it != mp.rend(); it++) {
    if (it->second >= 2) {
      continue;
    }
    a = it->first;
    break;
  }
  if (a == -1) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < N; i++) {
      if (a == A.at(i)) {
        cout << (i + 1) << endl;
        break;
      }
    }
  }
  return 0;
}
