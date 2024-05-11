#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/** (x, y)を45度回転してsqrt(2)倍した点を返す */
template<typename T> pair<T, T> rot45(T x, T y) { return make_pair(x - y, x + y); }

template<typename T> map<T, int> vec2mp(const vector<T> &vec) {
  map<T, int> mp;
  for (T value : vec) {
    mp[value]++;
  }
  return mp;
}

template<typename S, typename T> vector<pair<S, T> > mp2vec(const map<S, T> mp) {
  vector<pair<S, T> > vec;
  for (auto [s, t] : mp) {
    vec.emplace_back(s, t);
  }
  return vec;
}


/** 点集合psから2つを選ぶ全ての組み合わせに対する2点のマンハッタン距離の和を返す */
template<typename T> T manhattan_dist_sum(vector<pair<T, T> > ps) {
  auto contribution = [](vector<T> _xs) {
    int N = _xs.size();
    vector<pair<T, int> > xs = mp2vec(vec2mp(_xs));
    int M = xs.size();
    int left = 0;
    long long ans = 0;
    for (int m = 0; m < M - 1; m++) {
      int count = xs.at(m).second;
      left += count;
      int right = N - left;
      long long now = (long long)(xs.at(m + 1).first - xs.at(m).first) * left * right;
      ans += now;
    }
    return ans;
  };
  vector<T> xs, ys;
  for (auto [x, y] : ps) {
    xs.push_back(x);
    ys.push_back(y);
  }
  long long ans = contribution(xs) + contribution(ys);
  return ans;
}
  
int main() {
  int N;
  cin >> N;
  vector<pair<long long, long long> > ps0, ps1;
  for (int i = 0; i < N; i++) {
    long long X, Y;
    cin >> X >> Y;
    pair<long long, long long> p = rot45(X, Y);
    if (abs(p.first) % 2 == 0) {
      ps0.push_back(p);  // 偶数の点
    } else {
      ps1.push_back(p);  // 奇数の点
    }
  }
  long long ans0 = manhattan_dist_sum(ps0);
  long long ans1 = manhattan_dist_sum(ps1);
  long long ans = (ans0 + ans1) / 2;
  cout << ans << endl;
  return 0;
}
