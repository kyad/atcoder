// https://www.youtube.com/watch?v=wPN0YU6zLaA&t=6870s
// https://atcoder.jp/contests/abc331/submissions/48152940

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// 抽象化したセグメント木
#include <functional>
template<class X> struct SegTree {
  using FX = function<X(X, X)>;
  int n;  // n_以上の最小の2べき
  FX fx;  // 二項演算 X x X -> X
  X ex;  // 単位元
  vector<X> dat;  // dat[0]~dat[2*n-2]に値が入る

  void init(int n_, FX fx_, X ex_) {
    fx = fx_;
    ex = ex_;
    int x = 1;
    while (n_ > x) {
      x *= 2;
    }
    n = x;
    dat.resize(2 * n - 1, ex_);
  }
  SegTree(): n(), fx(), ex() {}
  SegTree(int n_, FX fx_, X ex_) { init(n_, fx_, ex_); }

  // 初期化 O(N) i: 0-indexed
  void set_init(int i, X x) { dat[i + n - 1] = x; }  // dat[n-1]~dat[2n-2]に値が入る
  void set_init1(int i, X x) { set_init(i - 1, x); }  // 1-indexed
  void build() {  // O(logN)
    for (int k = n - 2; k >= 0; k--) {
      dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }

  // 取得 O(N)
  X get(int i) { return dat[i + n - 1]; }  // 0-indexed
  X get1(int i) { return get(i - 1); }  // 1-indexed

  // 更新クエリ O(logN) i: 0-indexed
  void set(int i, X x) {
    i += (n - 1);
    dat[i] = x;
    while (i > 0) {  // 最下段から上がる
      i = (i - 1) / 2;  // parent
      dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }
  void set1(int i, X x) { set(i - 1, x); }  // 1-indexed

  // 取得クエリ O(logN) [a, b), a, b: 0-indexed
  X prod(int a, int b) { return prod_sub(a, b, 0, 0, n); }
  X prod1(int a, int b) { return prod(a - 1, b - 1); }  // 1-indexed
  X prod_sub(int a, int b, int k, int l, int r) {
    // k: 現在見ているノードの位置 [l, r): dat[k]が表している区間
    if (r <= a || b <= l) {  // 範囲外
      return ex;
    } else if (a <= l && r <= b) {  // 範囲内
      return dat[k];
    } else {  // 一部区間が被る時
      X vl = prod_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      X vr = prod_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return fx(vl, vr);
    }
  }
};

template<class X> ostream& operator<<(ostream& os, const SegTree<X> &segtree) {
  int depth = 0;
  int temp = segtree.n;
  while (temp > 0) {
    temp /= 2;
    depth++;
  }
#if 0
  int d0 = 0;  // Show all tree
#else
  int d0 = depth - 1;  // Show bottom
#endif
  for (int d = d0; d < depth; d++) {
    int left = (1<<d) - 1;
    int right = (1<<(d+1)) - 1;
    for (int i = left; i < right; i++) {
      //os << "["<< (i - left) << "]=";
      X val = segtree.dat[i];
      os << val;
      //if (abs(val) == 4e18) { if (val < 0) {os << '-'; } os << "inf"; } else { os << val; }
      if (i != right - 1) os << ' ';
    }
  }
  return os;
}

// SegTreeの型
struct D {
  unsigned long long h;  // ハッシュ値
  unsigned long long l;  // 長さのベキ。x^l
  D() {};
  D(unsigned long long _h, unsigned long long _l): h(_h), l(_l) {};
};
ostream& operator<<(ostream& os, const struct D d) {
  os << '(' << d.h << "," << d.l << ')';
  return os;
}

// SegTreeでハッシュ計算するローリングハッシュ
// hash(S) = S[0] * base^0 + S[1] * base^1 + ... +  S[N] * base^(N-1)
#include <ctime>
#include <random>
using Hash = unsigned long long;
struct RollingHashSegtree {
  static const Hash MOD = (1ULL<<61) - 1;  // MOD=2^61-1

  int N;
  string A;  // デバッグ用
  Hash base = 10000000007;
  SegTree<D> seg;

  // x mod MODを返す
  Hash mod(Hash x) {
    const Hash MASK61 = MOD;
    Hash xu = x>>61;
    Hash xd = x & MASK61;
    Hash ans = xu + xd;
    if (ans >= MOD) {
      ans -= MOD;
    }
    return ans;
  }
  
  // (a * b) mod MODを返す
  Hash mul(Hash a, Hash b) {
    const Hash MASK30 = (1ULL<<30) - 1;
    const Hash MASK31 = (1ULL<<31) - 1;
    Hash au = a>>31;
    Hash ad = a & MASK31;
    Hash bu = b>>31;
    Hash bd = b & MASK31;
    Hash mid = ad * bu + au * bd;
    Hash midu = mid>>30;
    Hash midd = mid & MASK30;
    Hash ans = au * bu * 2 + midu + (midd<<31) + ad * bd;
    ans = mod(ans);
    return ans;
  }

  // ランダムなbaseを決めたい時に使う。RollingHashSegtree::random_base()で呼ぶ
  static Hash random_base() {
    time_t now = time(nullptr);
    mt19937_64 mt((unsigned long long)now);
    uniform_int_distribution<unsigned long long> dist(1ULL, MOD - 1);
    return dist(mt);
  }

  // 初期化 O(NlogN)
  void build(const string &A) {
    N = A.size();
    // SegTree
    auto fx = [&](D x1, D x2) -> D {
      // x1とx2を連結したハッシュはx1+x2*l1
      Hash h = mod(x1.h + mul(x2.h, x1.l));
      Hash l = mul(x1.l, x2.l);
      return D(h, l);
    };
    D ex(0, 1);  // 単位元
    seg.init(N, fx, ex);
    for (int n = 0; n < N; n++) {
      seg.set(n, D((Hash)A.at(n), base));
    }
  }

  // コンストラクタ
  RollingHashSegtree(const string &_A, Hash _base) : A(_A), base(_base) { build(_A); }

  // [a, b)のハッシュを取得 O(logN)
  Hash get(int a, int b) {  // 0-indexed
    D d = seg.prod(a, b);
    return d.h;
  }

  // aをxに更新する O(logN)
  void set(int i, char x) {
    A.at(i) = x;
    seg.set(i, D((Hash)x, base));
  }
};

ostream& operator<<(ostream& os, const RollingHashSegtree rh) {
  os << "N=" << rh.N << endl;
  os << "A=" << rh.A << endl;
  os << "base=" << rh.base << endl;
  os << "seg=" << rh.seg;
  return os;
}
// 使い方
//  Hash base = RollingHashSegtree::random_base();  // ハッシュを比較するためには共通にする必要がある
//  RollingHashSegtree rh_s(S, base);
//  RollingHashSegtree rh_t(T, base);
//  Hash hash_s = rh_s.get(L, R + 1);
//  Hash hash_t = rh_t.get(N - 1 - R, N - 1 - L + 1);
//  bool ans = (hash_s == hash_t);

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  string T(S);
  reverse(T.begin(), T.end());
  Hash base = RollingHashSegtree::random_base();
  RollingHashSegtree rh_s(S, base);
  RollingHashSegtree rh_t(T, base);

  for (int q = 0; q < Q; q++) {
    int type;
    cin >> type;
    if (type == 1) {
      int X;
      char C;
      cin >> X >> C;
      X--;
      rh_s.set(X, C);
      rh_t.set(N - 1 - X, C);
    } else {
      int L, R;
      cin >> L >> R;
      L--; R--;
      Hash hash_s = rh_s.get(L, R + 1);
      Hash hash_t = rh_t.get(N - 1 - R, N - 1 - L + 1);
      bool ans = (hash_s == hash_t);
      cout << (ans ? "Yes" : "No") << '\n';
    }
  }
  return 0;
}
