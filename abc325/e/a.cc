#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N;
  long long A, B, C;
  cin >> N >> A >> B >> C;
  vector<vector<long long> > D(N, vector<long long>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> D.at(i).at(j);
    }
  }

  vector<vector<pair<int, long long> > > graph0(N);
  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      long long dist = D[u][v] * A;
      graph0[u].push_back(make_pair(v, dist));
    }
  }

  vector<vector<pair<int, long long> > > graph1(N);
  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      long long dist = 0;
      if (u != v) {
        dist = D[u][v] * B + C;
      }
      graph1[u].push_back(make_pair(v, dist));
    }
  }

  const long long INF = 4e18;
  vector<long long> dist0(N, INF);
  {
    // Dijkstra's algorithm (O|E|log|V|)
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
    int start = 0;
    dist0.at(start) = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
      long long dist0u = pq.top().first;
      int u = pq.top().second;
      pq.pop();
      if (dist0u > dist0.at(u)) {
        continue;  // Garbage
      }
      for (pair<int, long long> p : graph0.at(u)) {
        int v = p.first;
        long long cost = p.second;
        if (dist0u + cost < dist0.at(v)) {
          dist0.at(v) = dist0u + cost;
          pq.push(make_pair(dist0.at(v), v));
        }
      }
    }
  }

  vector<long long> dist1(N, INF);
  {
    // Dijkstra's algorithm (O|E|log|V|)
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
    int start = N - 1;
    dist1.at(start) = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
      long long dist1u = pq.top().first;
      int u = pq.top().second;
      pq.pop();
      if (dist1u > dist1.at(u)) {
        continue;  // Garbage
      }
      for (pair<int, long long> p : graph1.at(u)) {
        int v = p.first;
        long long cost = p.second;
        if (dist1u + cost < dist1.at(v)) {
          dist1.at(v) = dist1u + cost;
          pq.push(make_pair(dist1.at(v), v));
        }
      }
    }
  }

  long long ans = INF;
  for (int u = 0; u < N; u++) {
    long long now = dist0.at(u) + dist1.at(u);
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
