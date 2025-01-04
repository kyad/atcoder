#if 1
// debug
// mintを使う場合はmintの後に置くこと
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
#define hr std::cerr << "----------------" << std::endl;
#define hr2 std::cerr << "================" << std::endl;
#define print0(a, c) std::cerr << #a << '=' << a << c;
#define print1(a) print0(a, '\n');
#define print2(a, b) print0(a, '\t'); print1(b);
#define print3(a, b, c) print0(a, '\t'); print2(b, c);
#define print4(a, b, c, d) print0(a, '\t'); print3(b, c, d);
#define print5(a, b, c, d, e) print0(a, '\t'); print4(b, c, d, e);
#define print6(a, b, c, d, e, f) print0(a, '\t'); print5(b, c, d, e, f);
#define print7(a, b, c, d, e, f, g) print0(a, '\t'); print6(b, c, d, e, f, g);
#define print8(a, b, c, d, e, f, g, h) print0(a, '\t'); print7(b, c, d, e, f, g, h);
#define print9(a, b, c, d, e, f, g, h, i) print0(a, '\t'); print8(b, c, d, e, f, g, h, i);
#define print10(a, b, c, d, e, f, g, h, i, j) print0(a, '\t'); print9(b, c, d, e, f, g, h, i, j);
#define print_select(a, b, c, d, e, f, g, h, i, j, k, ...) k
#define print(...) print_select(__VA_ARGS__, print10, print9, print8, print7, print6, print5, print4, print3, print2, print1)(__VA_ARGS__)
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template<class T1, class T2, class T3> ostream& operator<<(ostream& os, const tuple<T1, T2, T3> &t) { os << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")"; return os; }
template<class T1, class T2, class T3, class T4> ostream& operator<<(ostream& os, const tuple<T1, T2, T3, T4> &t) { os << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ", " << get<3>(t) << ")"; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T> &v) { int MOD = -1; int N = v.size(); os << '[';
  for (int i = 0; i < N; i++) {
    //os << "["<< i << "]=";
    os << v[i];
    //if (abs(v[i]) == 4e18) { if (v[i] < 0) {os << '-'; } os << "inf"; } else { os << v[i]; }
    if (i == N - 1) { continue; }
    else if (MOD > 0 && i % MOD == (MOD - 1)) { os << '\n'; }
    else { os << ' '; }
  } os << ']'; return os; }
template<class T> ostream& operator<<(ostream& os, const set<T> &s) {
  vector<T> v; for (typename set<T>::iterator it = s.begin(); it != s.end(); it++) { v.push_back(*it); };
  os << v; return os; }
template<class T> ostream& operator<<(ostream& os, const multiset<T> &ms) {
  vector<T> v; for (typename multiset<T>::iterator it = ms.begin(); it != ms.end(); it++) { v.push_back(*it); };
  os << v; return os; }
template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1, T2> &m) {
  vector<T2> v; os << '['; size_t i = m.size();
  for (typename map<T1, T2>::const_iterator it = m.begin(); it != m.end(); it++) {
    os << '{' << it->first << ": " << it->second << '}'; if (i > 1) { os << ' '; } i--; }
  os << ']'; return os; }
template<class T> ostream& operator<<(ostream& os, const queue<T> &q) {
  vector<T> v; queue<T> _q(q); while (!_q.empty()) { v.push_back(_q.front()); _q.pop(); } os << v; return os; }
template<class T> ostream& operator<<(ostream& os, const priority_queue<T> &q) {
  vector<T> v; priority_queue<T> _q(q); while (!_q.empty()) { v.push_back(_q.top()); _q.pop(); } os << v; return os; }
template<class T> ostream& operator<<(ostream& os, const priority_queue<T, vector<T>, greater<T> > &q) {
  vector<T> v; priority_queue<T, vector<T>, greater<T> > _q(q); while (!_q.empty()) { v.push_back(_q.top()); _q.pop(); } os << v; return os; }
template<class T> ostream& operator<<(ostream& os, const deque<T> &dq) {
  vector<T> v; for (auto it = dq.begin(); it != dq.end(); it++) { v.push_back(*it); } os << v; return os; }
template<class T> ostream& operator<<(ostream& os, const stack<T> &s) {
  vector<T> v; stack<T> _s(s); while (!_s.empty()) { v.push_back(_s.top()); _s.pop(); } reverse(v.begin(), v.end()); os << v; return os; }
// 2d-matrix
template<class T> ostream& operator<<(ostream& os, const vector<vector<T> > &v) {
  int y0 = 0;
  int y1 = (int)v.size() - 1;
  for (int i = y0; i <= y1; i++) {
    os << (i == 0 ? "[[" : " [");
    int x0 = 0;
    int x1 = (int)v[i].size() - 1;
    for (int j = x0; j <= x1; j++) {
      os << v[i][j];
      if (j != x1) {
        os << ' ';
      }
    }
    os << (i == y1 ? "]]" : "]\n");
  }
  return os;
}
#endif
// --------


#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// xをbase進数で見た時の桁数を返す
int digits(long long x, int base) { int d = 0; while (x > 0) { x /= base; d++; } return d; }

// m^n, O(log n)
long long power(long long m, long long n, long long mod=1e18) {
  long long a = m % mod;
  long long ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return ans;
}

long long naive(long long N) {
  long long ans = 0;
  for (int n = 10; n <= N; n++) {
    int d = digits(n, 10);
    vector<int> a(d);  // a[i]の上からiケタ目
    int nn = n;
    for (int i = 0; i < d; i++) {
      a.at(d - 1 - i) = nn % 10;
      nn /= 10;
    }
    bool ok = true;
    for (int i = 1; i <= d - 1; i++) {
      if (a[i] >= a[0]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans++;
    }
  }
  return ans;
}

int main() {
  long long L, R;
  cin >> L >> R;

  // d桁のヘビ数を返す
  auto g = [&](int d) {
    long long ans = 0;
    for (int i = 1; i <= 9; i++) {  // 上から1桁目
      ans += power(i, d - 1);
    }
    return ans;
  };

  // n以下のヘビ数を返す
  auto f = [&](long long n) {
    int d = digits(n, 10);
    vector<int> a(d);  // a[i]の上からiケタ目
    for (int i = 0; i < d; i++) {
      a.at(d - 1 - i) = n % 10;
      n /= 10;
    }
    print(d, a);
    long long ans = 0;
    for (int i = 0; i < d; i++) {
      hr;print(i);
      // 上からi-1桁目までaで確定しているとして、
      // i桁目がa[i]-1以下の組み合わせを数える
      long long now = 0;
      if (i == 0) {  // 1桁目は特別扱い
        for (int j = 1; j <= a[0] - 1; j++) {
          now += power(j, d - 1);
        }
        print(now);
        ans += now;
      } else {
        now = min(a[i], a[0]);
        now *= power(a[0], d - 1 - i);
        print(now);
        ans += now;
        if (a[i] >= a[0]) {  // 6472の7のパターン
          break;
        }
      }
    }
    // 最後、N自身の処理
    long long now = 1;
    for (int i = 1; i < d; i++) {
      if (a[i] >= a[0]) {
        now = 0;
      }
    }
    print(now);
    ans += now;

    // d桁以下の処理
    for (int i = 2; i <= d - 1; i++) {
      long long now = g(i);
      ans += now;
    }
    return ans;
  };

#if 0
  long long ans = f(R);
  hr2;print(ans);
  ans -= f(L - 1);
#else  
  long long ans = naive(R);
  ans -= naive(L - 1);
#endif  
  cout << ans << endl;
  return 0;
}
