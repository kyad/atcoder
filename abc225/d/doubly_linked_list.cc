#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// 双方向リスト
struct DoublyLinkedList {
  int N;
  vector<int> next;  // 次。-1は次が無い
  vector<int> prev;  // 前。-1は前が無い
  // コンストラクタ。Nは要素数
  DoublyLinkedList(int _N): N(_N) {
    next.resize(N, -1);
    prev.resize(N, -1);
  }
  // aの後ろにbを結合する。0-indexed. O(1)
  void connect(int a, int b) {
    assert(0 <= a && a < N);
    assert(0 <= b && b < N);
    assert(next.at(a) == -1);
    next.at(a) = b;
    assert(prev.at(b) == -1);
    prev.at(b) = a;
  }
  // aとbを分離する。0-indexed. O(1)
  void separate(int a, int b) {
    assert(0 <= a && a < N);
    assert(0 <= b && b < N);
    assert(next.at(a) == b);
    next.at(a) = -1;
    assert(prev.at(b) == a);
    prev.at(b) = -1;
  }
  // aを含む連結成分の先頭番号を返す。0-indexed. O(N)
  int top(int a) {
    assert(0 <= a && a < N);
    while (prev.at(a) != -1) {
      a = prev.at(a);
    }
    return a;
  }
};

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  DoublyLinkedList dl(N);
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      dl.connect(x, y);
    } else if (type == 2) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      dl.separate(x, y);
    } else {
      int x;
      cin >> x;
      x--;
      vector<int> ans;
      for (int a = dl.top(x); a != -1; a = dl.next[a]) {
        ans.push_back(a + 1);
      }
      cout << ans.size() << ' ';
      dumpvec(ans);
    }
  }
  return 0;
}
