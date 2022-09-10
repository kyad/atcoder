#include <iostream>
#include <vector>
using namespace std;

// debug
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
#define hr std::cout << "----------------" << std::endl;
#define print0(a, c) std::cout << #a << '=' << a << c;
#define print1(a) print0(a, '\n');
#define print2(a, b) print0(a, '\t'); print1(b);
#define print3(a, b, c) print0(a, '\t'); print2(b, c);
#define print4(a, b, c, d) print0(a, '\t'); print3(b, c, d);
#define print5(a, b, c, d, e) print0(a, '\t'); print4(b, c, d, e);
#define print6(a, b, c, d, e, f) print0(a, '\t'); print5(b, c, d, e, f);
#define print7(a, b, c, d, e, f, g) print0(a, '\t'); print6(b, c, d, e, f, g);
#define print8(a, b, c, d, e, f, g, h) print0(a, '\t'); print7(b, c, d, e, f, g, h);
#define print_select(a, b, c, d, e, f, g, h, i, ...) i
#define print(...) print_select(__VA_ARGS__, print8, print7, print6, print5, print4, print3, print2, print1)(__VA_ARGS__)
template<class T> ostream& operator<<(ostream& os, const vector<T> &v) { int MOD = -1; size_t N = v.size(); os << '[';
  for (size_t i = 0; i < N; i++) { os << v[i];
    if (i == N - 1) { continue; }
    else if (MOD > 0 && i % MOD == (MOD - 1)) { os << '\n'; }
    else { os << ' '; }
  } os << ']'; return os; }
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template<class T1, class T2, class T3> ostream& operator<<(ostream& os, const tuple<T1, T2, T3> &t) { os << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")"; return os; }
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


long long N;
long long mod(long long a) {
  return (a + N * 10) % N;
}

long long ceil(long long a, long long b) {
  return (a + b - 1) / b;
}

int main() {
  cin >> N;
  vector<long long> P(N);  // 最初の位置→料理番号
  for (long long n = 0; n < N; n++) {
    cin >> P.at(n);
  }
  vector<long long> pos(N, -1);  // 料理番号→最初の位置
  for (long long i = 0; i < N; i++) {
    pos[P[i]] = i;
  }
  long long d = 0;
  long long dx = 0;
  vector<long long> dxp2(N, 0);
  vector<long long> dxm1(N, 0);
  for (long long i = 0; i < N; i++) {  // 人iに対するループ
    int d0;
    int dx0;
    if (mod(pos[i] - i) <= N / 2) {
      d0 = mod(pos[i] - i);
    } else {
      d0 = mod(i - pos[i]);
    }
    if (N % 2 == 1 && mod(pos[i] - i) == N / 2) {
      dx0 = 0;
    } else if (mod(pos[i] - i) < N / 2) {
      dx0 = 1;
    } else {
      dx0 = -1;
    }
    d += d0;
    dx += dx0;
    long long a = mod(i + (N / 2) - pos[i]);
    dxm1[a]++;
    long long b = mod(i + ceil(N, 2) - pos[i]);
    dxm1[b]++;
    long long c = mod(i - pos[i]);
    dxp2[c]++;
  }
  const long long INF = 4e18;
  long long ans = INF;
  for (long long k = 0; k < N; k++) {
    ans = min(ans, d);
    if (k > 0) {
      dx -= dxm1[k];
      dx += dxp2[k] * 2;
    }
    d += dx;
  }
  cout << ans << endl;
  return 0;
}
