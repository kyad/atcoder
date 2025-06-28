#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool> > graph(N, vector<bool>(N, false));
  for (int j = 0; j < M; j++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    graph.at(A).at(B) = true;
    graph.at(B).at(A) = true;
  }
  auto count = [&](const vector<int> &C) {
    int K = C.size();
    assert(K >= 3);
    int ans = 0;
    for (int k = 0; k < K; k++) {
      int u = C.at(k);
      int n = C.at((k + 1) % K);  // 次
      int p = C.at((k - 1 + K) % K);  // 前
      for (int v = 0; v < N; v++) {
        if (u == v) {
          continue;
        }
        if (v == n || v == p) {
          if (graph.at(u).at(v) == false) {  // 追加しないといけない
            if (u < v) {
              ans++;
            }
          }
        } else {
          if (graph.at(u).at(v) == true) {  // 削除しないといけない
            if (u < v) {
              ans++;
            }
          }
        }
      }
    }
    return ans;
  };
  // 1. 1個のループの時
  int ans1 = INF;
  {
    // 順列初期化
    vector<int> P(N, -1);
    for (int i = 0; i < N; i++) {
      P.at(i) = i;
    }
    // 順列全探索
    do {
      int now = count(P);
      ans1 = min(ans1, now);
    } while (next_permutation(P.begin(), P.end()));
  }
  // 2. 2個のループの時
  int ans2 = INF;
  {
    // 順列初期化
    vector<int> P(N + 1, -1);  // Nは切れ目
    for (int i = 0; i <= N; i++) {
      P.at(i) = i;
    }
    // 順列全探索
    do {
      int k = 0;
      vector<vector<int> > C(2);
      for (int i = 0; i <= N; i++) {
        if (P.at(i) == N) {  // 切れ目
          k++;
        } else {
          C.at(k).push_back(P.at(i));
        }
      }
      bool ok = true;  // 両方ともサイズ3以上か
      for (int k = 0; k < 2; k++) {
        if (C.at(k).size() < 3) {
          ok = false;
        }
      }
      if (!ok) {
        continue;
      }
      int now0 = count(C.at(0));
      int now1 = count(C.at(1));
      int now = now0 + now1;
      ans2 = min(ans2, now);
    } while (next_permutation(P.begin(), P.end()));
  }
  int ans = min(ans1, ans2);
  cout << ans << endl;
  return 0;
}
