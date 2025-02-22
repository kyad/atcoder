#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
  int N;
  cin >> N;
  vector<string> C(N);
  for (int y = 0; y < N; y++) {
    cin >> C.at(y);
  }
  vector<vector<int> > dist(N, vector<int>(N, INF));
  queue<pair<int, int> > q;
  // 自明な回文
  // 空文字
  for (int i = 0; i < N; i++) {
    dist.at(i).at(i) = 0;
    q.push(make_pair(i, i));
  }
  // エッジ
  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      if (C.at(u).at(v) != '-') {
        if (dist.at(u).at(v) == INF) {
          dist.at(u).at(v) = 1;
          q.push(make_pair(u, v));
        }
      }
    }
  }
  while (!q.empty()) {
    int from = q.front().first;
    int to = q.front().second;
    q.pop();
    for (int u = 0; u < N; u++) {
      char d = C.at(u).at(from);
      if (d == '-') {
        continue;
      }
      for (int v = 0; v < N; v++) {
        char e = C.at(to).at(v);
        if (e == '-') {
          continue;
        }
        if (d == e) {
          if (dist.at(u).at(v) == INF) {
            dist.at(u).at(v) = dist.at(from).at(to) + 2;
            q.push(make_pair(u, v));
          }
        }
      }
    }
  }

  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      if (dist.at(u).at(v) == INF) {
        dist.at(u).at(v) = -1;
      }
    }
  }

  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      cout << dist.at(u).at(v) << " \n"[v == N - 1];
    }
  }
  return 0;
}

