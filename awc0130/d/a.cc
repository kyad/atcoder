#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int W;

struct UnionFind {
  vector<int> parent, _size;
  int _num_unions;
  // UnonFindが範囲の時の左端と右端
  vector<int> _left;
  vector<int> _right;

  vector<int> _top;
  vector<int> _bottom;
  // 追加

  UnionFind(int n) : parent(n, -1), _size(n, 1), _num_unions(n) {
    _left.resize(n, 0);
    _right.resize(n, 0);
    _top.resize(n, 0);
    _bottom.resize(n, 0);
    for (int i = 0; i < n; i++) {
      int x = i % W;
      int y = i / W;
      _left.at(i) = x;
      _right.at(i) = x;
      _top.at(i) = y;
      _bottom.at(i) = y;
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
    int ntop = min(_top.at(x), _top.at(y));
    _top.at(x) = ntop;
    int nbottom = max(_bottom.at(x), _bottom.at(y));
    _bottom.at(x) = nbottom;
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

  int top(int x) {
    return _top[root(x)];
  }

  int bottom(int x) {
    return _bottom[root(x)];
  }
};

int main() {
  int H, N;
  cin >> H >> W >> N;
  vector<vector<int>> board(H + 2, vector<int>(W + 2, 0));
  for (int i = 0; i < N; i++) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    board.at(A).at(C)++;
    board.at(A).at(D + 1)--;
    board.at(B + 1).at(C)--;
    board.at(B + 1).at(D + 1)++;
  }
  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= W; x++) {
      board.at(y).at(x + 1) += board.at(y).at(x);
    }
  }
  for (int x = 1; x <= W; x++) {
    for (int y = 1; y <= H; y++) {
      board.at(y + 1).at(x) += board.at(y).at(x);
    }
  }
  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= W; x++) {
      board.at(y).at(x) %= 2;
    }
  }
  vector<vector<int>> imos(board);
  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= W; x++) {
      imos.at(y).at(x) += imos.at(y).at(x - 1);
    }
  }
  for (int x = 1; x <= W; x++) {
    for (int y = 1; y <= H; y++) {
      imos.at(y).at(x) += imos.at(y - 1).at(x);
    }
  }
  auto encode = [&](int y, int x) {
    y--; x--;
    assert(0 <= y && y < H);
    assert(0 <= x && x < W);
    return y * W + x;
  };
  auto decode = [&](int z, int &y, int &x) -> void {
    y = z / W;
    x = z % W;
    y++; x++;
  };
  UnionFind uf(H * W);
  const int dy[4] = {0, -1, 0, +1};
  const int dx[4] = {+1, 0, -1, 0};
  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= W; x++) {
      if (board.at(y).at(x) == 0) {
        continue;
      }
      int z = encode(y, x);
      for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny <= 0 || ny >= H + 1 || nx <= 0 || nx >= W + 1 || board.at(ny).at(nx) == 0) {
          continue;
        }
        int nz = encode(ny, nx);
        uf.unite(z, nz);
      }
    }
  }

  vector<int> top, bottom, left, right;
  for (int z = 0; z < H * W; z++) {
    int y, x;
    decode(z, y, x);
    if (board.at(y).at(x) == 0) {
      continue;
    }
    if (z == uf.root(z)) {
      top.push_back(uf.top(z) + 1);
      bottom.push_back(uf.bottom(z) + 1);
      left.push_back(uf.left(z) + 1);
      right.push_back(uf.right(z) + 1);
    }
  }
  int L = top.size();

  int M;
  cin >> M;
  for (int j = 0; j < M; j++) {
    int P, Q, R, S;
    cin >> P >> Q >> R >> S;
    int ans0 = imos.at(Q).at(S) - imos.at(Q).at(R - 1) - imos.at(P - 1).at(S) + imos.at(P - 1).at(R - 1);
    int ans1 = 0;
    for (int l = 0; l < L; l++) {
      if (P <= top.at(l) && bottom.at(l) <= Q && R <= left.at(l) && right.at(l) <= S) {
        ans1++;
      }
    }
    cout << ans0 << ' ' << ans1 << '\n';
  }
  return 0;
}
