#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
  }
  vector<priority_queue<pair<int, int>>> graph(N);
  for (int j = 0; j < M; j++) {
    int U, V;
    cin >> U >> V;
    U--;
    V--;
    graph.at(U).push(make_pair(B.at(V), V));
  }
  const int INF = 1e9;
  vector<int> ans;
  vector<bool> visited(N, false);
  vector<pair<int, int>> bu(N);
  for (int u = 0; u < N; u++) {
    if (u == 0) {
      bu.at(u) = make_pair(INF, u);
    } else {
      bu.at(u) = make_pair(B.at(u), u);
    }
  }
  sort(bu.begin(), bu.end());
  reverse(bu.begin(), bu.end());
  for (auto [_, start]: bu) {
    if (visited.at(start)) {
      continue;
    }
    int u = start;
    while (true) {
      visited.at(u) = true;
      ans.push_back(u + 1);
      int nu = -1;
      while (!graph.at(u).empty()) {
        int v = graph.at(u).top().second;
        graph.at(u).pop();
        if (visited.at(v)) {
          continue;
        } else {
          nu = v;
          break;
        }
      }
      if (nu == -1) {
        break;
      }
      u = nu;
    }
  }
  dump(ans);
  return 0;
}
