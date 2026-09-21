#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  multiset<int> ms;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    ms.insert(A);
  }
  int turn = 0;
  long long takahashi = 0;
  long long aoki = 0;
  while (!ms.empty()) {
    if (turn == 0) {
      long long now = *ms.rbegin();
      takahashi += now;
      ms.erase(ms.find(now));
    } else {
      long long now = *ms.rbegin();
      aoki +=  now;
      ms.erase(ms.find(now));
    }
    turn = 1 - turn;
  }
  long long ans = takahashi;
  cout << ans << '\n';
  return 0;
}
