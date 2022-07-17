// https://atcoder.jp/contests/abc260/tasks/abc260_f

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int S, T, M;
  cin >> S >> T >> M;
  vector<vector<int> > graph(S);
  vector<pair<int, int> > UV(M);
  for (int m = 0; m < M; m++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    UV.at(m) = make_pair(u, v);
  }
  sort(UV.begin(), UV.end());
  for (int m = 0; m < M; m++) {
    int u = UV.at(m).first;
    int v = UV.at(m).second;
    graph[u].push_back(v);
  }

  vector<vector<int> > count(T, vector<int>(T, -1));
  for (int s = 0; s < S; s++) {
    for (size_t i = 0; i < graph[s].size(); i++) {
      const int t1 = graph[s][i];
      for (size_t j = i + 1; j < graph[s].size(); j++) {
        const int t2 = graph[s][j];
        if (count[t1 - S][t2 - S] >= 0) {
          const int s1 = count[t1 - S][t2 - S];
          cout << (s1 + 1) << ' ' << (s + 1) << ' ' << (t1 + 1) << ' ' << (t2 + 1) << endl;
          return 0;
        }
        count[t1 - S][t2 - S] = s;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
