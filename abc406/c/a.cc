#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
  }
  vector<long long> A;
  long long count = 0;
  for (int i = 1; i < N; i++) {
    if (P.at(i - 1) < P.at(i)) {  // 増加
      count++;
    } else {  // 減少に転じた時
      if (count != 0) {
        A.push_back(count);
      }
      count = 0;
    }
  }
  if (count != 0) {  // 末尾の処理
    A.push_back(count);
  }

  long long ans = 0;
  int M = A.size();
  for (int j = 1; j < M; j++) {
    long long now = A.at(j - 1) * A.at(j);
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
