#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N + 1);
  vector<vector<int>> B(N + 1);
  map<pair<int, int>, int> mp;
  vector<int> L(M), R(M);
  vector<tuple<int, int, int> > nunos;
  for (int j = 0; j < M; j++) {
    cin >> L.at(j) >> R.at(j);
    A.at(L.at(j)).push_back(R.at(j));
    B.at(R.at(j)).push_back(L.at(j));
    mp[make_pair(L.at(j), R.at(j))]++;
    int len = R.at(j) - L.at(j) + 1;
    nunos.push_back(make_tuple(len, L.at(j), R.at(j)));
  }
  sort(nunos.begin(), nunos.end());
  for (int k = 0; k <= N; k++) {
    A.at(k).push_back(-1);
    A.at(k).push_back(INF);
    sort(A.at(k).begin(), A.at(k).end());
    B.at(k).push_back(-1);
    B.at(k).push_back(INF);
    sort(B.at(k).begin(), B.at(k).end());
  }
  int Q;
  cin >> Q;
  map<pair<int, int>, bool> memo; //存在しない:不明 
  for (int qi = 0; qi < Q; qi++) {
    int S, T;
    cin >> S >> T;
    auto p = make_pair(S, T);
    bool ans;
    if (mp.contains(p)) {
      if (mp[p] >= 2) {
        ans = true;
      } else {
        // [S, T]が包含しているものがあるかチェック
        if (memo.contains(p)) {
          ans = memo[p];
        } else {
          ans = false;
          int len_now = T - S + 1;
          for (auto [len, L, R] : nunos) {
            if (len >= len_now) {
              break;
            }
            if (L == S && R == T) {
              continue;
            }
            if (S <= L && R <= T) {
              ans = true;
              break;
            }
          }
          memo[p] = ans;
        }
      }
    } else {
      int r1 = *prev(upper_bound(A.at(S).begin(), A.at(S).end(), T));
      int l1 = *lower_bound(B.at(T).begin(), B.at(T).end(), S);
      if (r1 == -1 || l1 == INF) {
        ans = false;
      } else {
        if (r1 + 2 <= l1) {
          ans = false;
        } else {
          ans = true;
        }
      }
    }
    cout << (ans ? "Yes" : "No") << '\n';
  }
  return 0;
}
