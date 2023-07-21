#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, T, M;
  cin >> N >> T >> M;
  // 相性が良ければtrue
  vector<vector<bool> > graph(N, vector<bool>(N, true));
  for (int m = 0; m < M; m++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    graph[A][B] = false;
    graph[B][A] = false;
  }
  vector<vector<int> > dp;
  vector<int> a;
  a.push_back(1<<0);
  dp.push_back(a);
  // i人目を入れる(0-indexed)
  for (int i = 1; i < N; i++) {
    vector<vector<int> > p;
    swap(dp, p);
    for (vector<int> A : p) {  // p = [A0, A1, ... , ]
      for (size_t j = 0; j < A.size(); j++) {  // A = [a0, a1, ... ]
        int a = A[j];
        // i - 1人目までの状態Aにおいて、各チームaにiを追加できるか確認する
        bool ok = true;
        for (int n = 0; n < N; n++) {
          if ((a >> n) & 1) {
            if (!graph[n][i]) {
              ok = false;
              break;
            }
          }
        }
        if (ok) {
          // チームaにiを追加する
          vector<int> now = A;
          now[j] |= (1<<i);
          dp.push_back(now);
        }
      }
      // Aのチーム数がT未満ならAに単騎を追加したやつもOK
      if ((int)A.size() < T) {
        vector<int> now = A;
        now.push_back(1<<i);
        dp.push_back(now);
      }
    }
  }
  long long ans = 0;
  for (vector<int> A : dp) {
    if ((int)A.size() == T) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
