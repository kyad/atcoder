// https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_d

#include <iostream>
#include <vector>
using namespace std;

// pair
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

pair<long long, long long> normalize(long long r) {
  long long ans = 0;
  while (r >= 10) {
    long long sum = 0;
    long long digits = 0;
    while (r > 0) {
      sum += (r % 10);
      r /= 10;
      digits++;
    }
    ans += (digits - 1);
    r = sum;
  }
  return make_pair(r, ans);
}

int main() {
  int M;
  cin >> M;
  long long ans = 0;
  vector<long long> r(M);
  for (int m = 0; m < M; m++) {
    int d;
    long long c;
    cin >> d >> c;
    ans += (c - 1);
    pair<long long, long long> p = normalize(c * d);
    cout << "m="<<m<<" c-1="<<(c-1)<<" p="<<p<<endl;
    r.at(m) = p.first;
    ans += p.second;
  }
  for (int m = 1; m < M; m++) {
    ans++;
    pair<long long, long long> p = normalize(r.at(m - 1) + r.at(m));
    cout << "m="<<m<<" p="<<p<<endl;
    r.at(m) = p.first;
    ans += p.second;
  }
  cout << ans << endl;
  return 0;
}
