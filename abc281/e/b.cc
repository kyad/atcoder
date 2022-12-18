// https://atcoder.jp/contests/abc281/tasks/abc281_e

#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  multiset<int> S, T;
  long long sum = 0;  // Sum of S
  auto add = [&](int a) {
    S.insert(a);
    sum += a;
    assert((int)S.size() <= K + 1);
    if ((int)S.size() == K + 1) {
      auto it = prev(S.end());
      T.insert(*it);
      sum -= *it;
      S.erase(it);
    }
  };
  // Init
  for (int n = 0; n < M; n++) {
    add(A[n]);
  }
  vector<long long> ans;
  ans.push_back(sum);

  for (int i = 0; i < N - M; i++) {
    // A[i]を取る
    if (S.count(A[i]) > 0) {
      S.erase(S.find(A[i]));
      sum -= A[i];
    } else {
      T.erase(T.find(A[i]));
    }
    // A[M + i]を加える
    if (S.empty() || A[M + i] < (*prev(S.end()))) {  // K==1の場合はSがemptyになる
      S.insert(A[M + i]);
      sum += A[M + i];
    } else {
      T.insert(A[M + i]);
    }
    // 個数を調整
    assert(((int)S.size() == K - 1) || ((int)S.size() == K) || ((int)S.size() == K + 1));
    if ((int)S.size() == K - 1) {
      // T -> S
      S.insert(*T.begin());
      sum += *T.begin();
      T.erase(T.begin());
    } else if ((int)S.size() == K + 1) {
      // S -> T
      auto it = prev(S.end());
      sum -= *it;
      T.insert(*it);
      S.erase(it);
    }
    ans.push_back(sum);
  }
  for (size_t i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
  }
  return 0;
}
