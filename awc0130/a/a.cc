#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  set<int> T, A;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'A') {
      A.insert(i);
    } else {
      T.insert(i);
    }
  }
  // チェック不要
  for (int j = 0; j < M; j++) {
    int R;
    cin >> R;
    R--;
    if (T.contains(R)) {
      T.erase(R);
      A.insert(R);
    } else {
      assert(A.contains(R));
      A.erase(R);
      T.insert(R);
    }
    // チェック
    if (T.size() == 0 || A.size() == 0) {
      cout << j + 1 << endl;
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}
