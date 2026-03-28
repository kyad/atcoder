#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

struct UnionFind {
  vector<int> parent, _size;
  int _num_unions;
  // UnonFindが範囲の時の左端と右端
  vector<int> _left;
  vector<int> _right;
  // 追加

  UnionFind(int n) : parent(n, -1), _size(n, 1), _num_unions(n) {
    _left.resize(n, 0);
    _right.resize(n, 0);
    for (int i = 0; i < n; i++) {
      _left.at(i) = i;
      _right.at(i) = i;
    }
    // 追加
  }

  int root(int x) {
    if (parent[x] == -1) {
      return x;
    } else {
      //return root(parent[x]);  // O(logN)
      return parent[x] = root(parent[x]);  // O(alpha(N))
    }
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return false;
    }
    if (_size[x] < _size[y]) {
      swap(x, y);  // Union by size
    }
    // xが新しい親
    parent[y] = x;
    _size[x] += _size[y];
    _num_unions--;

    // 範囲の更新
    int nleft = min(_left.at(x), _left.at(y));
    _left.at(x) = nleft;
    int nright = max(_right.at(x), _right.at(y));
    _right.at(x) = nright;
    // 追加

    return true;
  }

  int size(int x) {
    return _size[root(x)];
  }

  int num_unions() {  // unionの数(ひとまとまりになっているグループの数)を返す
    return _num_unions;
  }

  int left(int x) {
    return _left[root(x)];
  }

  int right(int x) {
    return _right[root(x)];
  }
};

int main() {
  int N;
  cin >> N;
  vector<vector<int> > A(N, vector<int>(N, 0));
  vector<tuple<int, int, int> > As;  // (A, i, j)
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      cin >> A.at(i).at(j);
      A.at(j).at(i) = A.at(i).at(j);
      As.push_back(make_tuple(A.at(i).at(j), i, j));
    }
  }
  sort(As.begin(), As.end());
  UnionFind uf(N);
  vector<vector<int> > graph(N);
  for (auto [A, i, j] : As) {
    if (!uf.issame(i, j)) {
      graph.at(i).push_back(j);
      graph.at(j).push_back(i);
      uf.unite(i, j);
    }
  }
  // 枝以外が大丈夫か確認する
  // BFS
  auto bfs = [&](int s) {
    //int s = 0;  // 探索開始ノード
    queue<int> todo;
    vector<int> dist(N, -1);
    dist.at(s) = 0;
    todo.push(s);
    while (!todo.empty()) {
      int u = todo.front();
      todo.pop();
      for (int v : graph.at(u)) {
        if (dist.at(v) < 0) {
          dist.at(v) = dist.at(u) + A.at(u).at(v);
          todo.push(v);
        }
        // if (dist.at(v) == dist.at(u) + 1) {  // 前に、uと同じ距離のノードからvに訪れていた場合の処理
        // }
      }
    }
    // Aとチェック
    for (int j = 0; j < N; j++) {
      if (s == j) {
        continue;
      }
      if (dist.at(j) != -1 && A.at(s).at(j) != dist.at(j)) {
        cout << "No" << endl;
        exit(0);
      }
    }
    
  };
  for (int i = 0; i < N; i++) {
    bfs(i);
  }
  cout << "Yes" << '\n';
  return 0;
}
