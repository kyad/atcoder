#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> V(N);
  for (int u = 0; u < N; u++) {
    cin >> V.at(u);
  }
  vector<vector<int> > graph(N);
  for (int u = 1; u <= N - 1; u++) {
    int P;
    cin >> P;
    P--;
    graph.at(P).push_back(u);
  }
  vector<long long> dp(N);
  auto f = [&](auto f, int u, int parent) -> void {
    dp.at(u) = V.at(u);
    if (parent != -1) {
      dp.at(u) += dp.at(parent);
    }
    for (int v : graph.at(u)) {
      f(f, v, u);
    }
  };
  f(f, 0, -1);
  for (int qi = 0; qi < Q; qi++) {
    int X;
    cin >> X;
    X--;
    cout << dp.at(X) << '\n';
  }
  return 0;
}
