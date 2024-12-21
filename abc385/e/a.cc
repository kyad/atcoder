#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > graph(N);
  for (int i = 0; i < N - 1; i++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph.at(U).push_back(V);
    graph.at(V).push_back(U);
  }
  vector<int> deg(N); // deg[u]: uの次数
  for (int u = 0; u < N; u++) {
    deg.at(u) = graph.at(u).size();
  }
  int ans = N;
  for (int u = 0; u < N; u++) {  // 中心をuで固定する
    // count[d]: 次数がdの個数
    map<int, int> count;
    for (int v : graph[u]) {
      count[deg[v]]++;
    }
    // countの個数の合計
    int sum = 0;
    for (auto [deg, cnt]: count) {
      sum += cnt;
    }
    int mx = 0;
    while (!count.empty()) {
      int degree = count.begin()->first;
      int cnt = count.begin()->second;
      int now = degree * sum;
      mx = max(mx, now);
      sum -= cnt;
      count.erase(count.begin());
    }
    int now = mx + 1;
    int remove = N - now;
    ans = min(ans, remove);
  }
  cout << ans << endl;
  return 0;
}
