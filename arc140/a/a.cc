// https://atcoder.jp/contests/arc140/tasks/arc140_a

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  int f;  // f(S)の値
  for (f = 1; f <= N; f++) {
    if (N % f > 0) {
      continue;
    }
    for (int i = 0; i < N; i++) {  // i: スタート位置
      int dist = 0;
      for (int k = 0; k < f; k++) {
        vector<int> count(26, 0);
        for (int j = k; j < N; j += f) {
          count[S[j] - 'a']++;
        }
        dist += (N / f - *max_element(count.begin(), count.end()));
      }
      if (dist <= K) {
        cout << f << endl;
        return 0;
      }
    }
  }
  assert(false);
  return 0;
}
