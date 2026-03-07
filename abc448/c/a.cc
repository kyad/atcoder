#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<int> AA(A);
  sort(AA.begin(), AA.end());
  multiset<int> ms;
  for (int i = 0; i < N; i++) {
    if (i >= 6) {
      break;
    }
    ms.insert(AA.at(i));
  }
  for (int qi = 0; qi < Q; qi++) {
    int K;
    cin >> K;
    multiset<int> ms2(ms);
    for (int k = 0; k < K; k++) {
      int B;
      cin >> B;
      B--;
      int a = A.at(B);
      if (ms2.contains(a)) {
        ms2.erase(ms2.find(a));  // xを1つだけ削除
      }
    }
    assert(!ms2.empty());
    int ans = *ms2.begin();
    cout << ans << '\n';
  }
  return 0;
}
