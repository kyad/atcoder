#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <set>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N), B(N), C(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
  }
  sort(A.begin(), A.end(), greater<long long>());
  sort(B.begin(), B.end(), greater<long long>());
  sort(C.begin(), C.end(), greater<long long>());
  priority_queue<tuple<long long, int, int, int> > pq;
  long long S = A.at(0) * B.at(0) + B.at(0) * C.at(0) + C.at(0) * A.at(0);
  pq.push(make_tuple(S, 0, 0, 0));
  set<tuple<int, int, int> > used;
  used.insert(make_tuple(0, 0, 0));
  long long ans = -1;
  for (int ki = 0; ki < K; ki++) {
    assert(!pq.empty());
    auto [S, i, j, k] = pq.top();
    pq.pop();
    if (i + 1 < N && !used.contains(make_tuple(i + 1, j, k))) {
      pq.push(make_tuple(A.at(i + 1) * B.at(j) + B.at(j) * C.at(k) + C.at(k) * A.at(i + 1), i + 1, j, k));
      used.insert(make_tuple(i + 1, j, k));
    }
    if (j + 1 < N && !used.contains(make_tuple(i, j + 1, k))) {
      pq.push(make_tuple(A.at(i) * B.at(j + 1) + B.at(j + 1) * C.at(k) + C.at(k) * A.at(i), i, j + 1, k));
      used.insert(make_tuple(i, j + 1, k));
    }
    if (k + 1 < N && !used.contains(make_tuple(i, j, k + 1))) {
      pq.push(make_tuple(A.at(i) * B.at(j) + B.at(j) * C.at(k + 1) + C.at(k + 1) * A.at(i), i, j, k + 1));
      used.insert(make_tuple(i, j, k + 1));
    }
    if (ki == K - 1) {
      ans = S;
    }
  }
  cout << ans << endl;
  return 0;  
}