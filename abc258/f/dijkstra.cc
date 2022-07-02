// https://atcoder.jp/contests/abc258/tasks/abc258_f
// https://github.com/drken1215/book_algorithm_solution/blob/master/codes/chap14/code_14_4.cpp

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int testcase() {
  long long B, K, SX, SY, GX, GY;
  cin >> B >> K >> SX >> SY >> GX >> GY;
  if (SX == GX && SY == GY) {
    cout << 0 << endl;
    return 0;
  }
  set<pair<long long, long long> > P;
  P.insert(make_pair(SX, SY));
  P.insert(make_pair(GX, GY));
  {
    long long rx = SX / B;
    P.insert(make_pair(B * rx, SY));
    P.insert(make_pair(B * (rx + 1), SY));
    long long ry = SY / B;
    P.insert(make_pair(SX, B * ry));
    P.insert(make_pair(SX, B * (ry + 1)));

    P.insert(make_pair(B * rx, B * ry));
    P.insert(make_pair(B * (rx + 1), B * ry));
    P.insert(make_pair(B * rx, B * (ry + 1)));
    P.insert(make_pair(B * (rx + 1), B * (ry + 1)));
  }
  {
    long long rx = GX / B;
    P.insert(make_pair(B * rx, GY));
    P.insert(make_pair(B * (rx + 1), GY));
    long long ry = GY / B;
    P.insert(make_pair(GX, B * ry));
    P.insert(make_pair(GX, B * (ry + 1)));

    P.insert(make_pair(B * rx, B * ry));
    P.insert(make_pair(B * (rx + 1), B * ry));
    P.insert(make_pair(B * rx, B * (ry + 1)));
    P.insert(make_pair(B * (rx + 1), B * (ry + 1)));
  }
  int N = P.size();
  vector<long long> X(N), Y(N);
  vector<bool> start(N), goal(N), edge(N), corner(N);
  map<pair<long long, long long>, int> mp;
  int n = 0;
  for (set<pair<long long, long long> >::iterator it = P.begin(); it != P.end(); it++) {
    long long x = it->first;
    long long y = it->second;
    mp[make_pair(x, y)] = n;
    X.at(n) = x;
    Y.at(n) = y;
    if (SX == x && SY == y) {
      start.at(n) = true;
    }
    if (GX == x && GY == y) {
      goal.at(n) = true;
    }
    if (x % B == 0 || y % B == 0) {
      edge.at(n) = true;
    }
    if (x % B == 0 && y % B == 0) {
      corner.at(n) = true;
    }
    n++;
  }
  vector<vector<pair<int, long long> > > graph(N);
  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      if (u == v) {
        continue;
      }
      if (start[u]) {
        if (goal[v]) {
          graph[u].push_back(make_pair(v, K * (abs(SX - GX) + abs(SY - GY))));
        }
      }
      if (start[u] || goal[u] || edge[u]) {
        if (X[u] == X[v] && Y[u] != Y[v]) {
          long long k = K;
          if (X[u] % B == 0) {
            k = 1;
          }
          graph[u].push_back(make_pair(v, k * abs(Y[u] - Y[v])));
        }
        if (X[u] != X[v] && Y[u] == Y[v]) {
          long long k = K;
          if (Y[u] % B == 0) {
            k = 1;
          }
          graph[u].push_back(make_pair(v, k * abs(X[u] - X[v])));
        }
      }
      if (corner[u]) {
        if (corner[v] || edge[v] && (X[u] == X[v] || Y[u] != Y[v])) {
          graph[u].push_back(make_pair(v, abs(X[u] - X[v]) + abs(Y[u] - Y[v])));
        }
      }
    }
  }
  int S = mp[make_pair(SX, SY)];
  int G = mp[make_pair(GX, GY)];

  // Dijkstra's algorithm for sparse graph (O|E|log|V|)
  const long long INF = 9e18;
  vector<long long> dist(N, INF);
  dist.at(S) = 0;
  priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
  pq.push(make_pair(0, S));
  while (!pq.empty()) {
    long long dist_min = pq.top().first;
    int dist_min_idx = pq.top().second;
    pq.pop();
    if (dist_min > dist.at(dist_min_idx)) {
      // garbage
      continue;
    }
    vector<pair<int, long long> > edges = graph.at(dist_min_idx);
    for (size_t i = 0; i < edges.size(); i++) {
      int v = edges.at(i).first;
      long long cost = edges.at(i).second;
      if (dist.at(v) > dist_min + cost) {
        dist.at(v) = dist_min + cost;
        pq.push(make_pair(dist.at(v), v));
      }
    }
  }
  cout << dist[G] << endl;
  return 0;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    testcase();
  }
  return 0;
}
