// https://www.youtube.com/live/Go0pDCf6Mvs?t=3683s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0, int end = -1) {
  if (end < 0) {
    end = x.size();
  }
  for (int i = start; i < end; i++) {
    cout << x.at(i) << (i + 1 == end ? '\n' : ' ');
  }
}

int main() {
  int N;
  cin >> N;
  vector<vector<int>> graph(N);
  vector<pair<int, int>> edges(N - 1);
  for (int j = 0; j < N - 1; j++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph.at(U).push_back(V);
    graph.at(V).push_back(U);
    edges.at(j) = make_pair(U, V);
  }
  vector<int> T(N);
  auto dfs0 = [&](auto dfs0, int u, int parent) -> int {
    T.at(u) = 1;
    for (int v : graph.at(u)) {
      if (v == parent) {
        continue;
      }
      T.at(u) += dfs0(dfs0, v, u);
    }
    return T.at(u);
  };
  dfs0(dfs0, 0, -1);
  vector<long long> X(N, 0);
  for (int j = 0; j < N - 1; j++) {
    auto [a, b] = edges.at(j);
    // aが根に近い方になるようにする
    if (T.at(a) < T.at(b)) {
      swap(a, b);
    }
    if (T.at(b) > N - T.at(b)) {
      X.at(b) += j + 1;
    } else {
      X.at(0) += j + 1;
      X.at(b) -= j + 1;
    }
  }
  auto dfs1 = [&](auto dfs1, int u, int parent) -> void {
    for (int v : graph.at(u)) {
      if (v == parent) {
        continue;
      }
      X.at(v) += X.at(u);
      dfs1(dfs1, v, u);
    }
  };
  dfs1(dfs1, 0, -1);
  dump(X);
  return 0;
}
