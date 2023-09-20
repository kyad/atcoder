#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

vector<int> naive(int N, int K, vector<int> P) {
  vector<int> ans(N);
  for (int n = 0; n < N; n++) {
    ans[0] = -1;
  }
  for (int i = 0; i <= N - K; i++) {
    vector<int> Q(P);
    sort(Q.begin() + i, Q.begin() + i + K);
    ans = max(ans, Q);
  }
  return ans;
}

pair<bool, vector<int> > solve2(int N, int K, vector<int> P) {
  // 2. もし[a, (全部aより上)]の形があれば、それをソートしたものが答え
  // 右程良いが、かぶってる中で一番左が良い。
  //print(P);
  set<int> st;
  for (int i = N - K + 1; i < N; i++) {
    st.insert(P[i]);
  }
  const int INF = 1e9;
  int mn = INF;
  for (int l = N - K; l >= 0; l--) {
    //print(l, st);
    if (P[l] < *st.begin()) {
      mn = l;
      //print(l, P[l], st, mn);
    } else {
      if (mn != INF) {
        break;
      }
    }
    st.erase(P[l + K - 1]);
    st.insert(P[l]);
  }
  if (mn < INF) {
    sort(P.begin() + mn, P.begin() + mn + K);
    return make_pair(true, P);
  }
  return make_pair(false, P);
}

vector<int> solve3(int N, int K, vector<int> P) {
  sort(P.begin() + N - K, P.begin() + N);
  return P;
}

vector<int> solve(int N, int K, vector<int> P) {
  // 1. もしK個連続で増加列があれば、答えはP
  vector<int> inc(N, 0);  // 何個連続で増加したか
  inc[0] = 1;
  for (int i = 1; i < N; i++) {
    if (P[i] > P[i - 1]) {
      inc[i] = inc[i - 1] + 1;
    } else {
      inc[i] = 1;
    }
  }
  //print(inc);
  for (int i = 0; i < N; i++) {
    if (inc[i] >= K) {
      //print(inc, i, inc[i]);
      return P;
    }
  }
  // 2.
  auto [b2, ans2] = solve2(N, K, P);
  // 3. 末尾のK個をソートしたもの
  vector<int> ans = solve3(N, K, P);
  if (b2) {
    ans = max(ans, ans2);
  }
  return ans;
};


int main() {
  int N, K;
  cin >> N >> K;
  vector<int> P(N, -1);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
  }
  auto ans = solve(N, K, P);
  dumpvec(ans);
  return 0;
}
