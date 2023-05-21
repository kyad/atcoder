#if 1
// debug
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
template<class T> ostream& operator<<(ostream& os, const vector<T> &v) { int MOD = -1; int N = v.size(); os << '[';
  for (int i = 0; i < N; i++) {
    //os << "["<< i << "]=";
    os << v[i];
    //if (abs(v[i]) == 4e18) { if (v[i] < 0) {os << '-'; } os << "inf"; } else { os << v[i]; }
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
#endif


#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

string f(string S) {
  int N = S.size();
  vector<int> A;  // 0-indexed
  vector<int> B;  // 0-indexed
  for (int n = 0; n < N - 1; n++) {
    if (S[n] == 'A') {
      A.push_back(n);
    } else {
      B.push_back(n);
    }
  }
  string T;
  for (int n : A) {
    T.push_back(S[n + 1]);
  }
  for (int n : B) {
    T.push_back(S[n + 1]);
  }
  return T;
}

void testcase() {
  int _N;
  cin >> _N;
  string S;
  cin >> S;
  int N = S.size();
  hr2;print(S);
  for (int n = 0; n < N - 1; n++) {
    S = f(S);
    print(n, S);
  }
  cout << S << endl;
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    testcase();
  }
  return 0;
}
