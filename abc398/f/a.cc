#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// ローリングハッシュ
#include <ctime>
#include <random>
struct RollingHash {
  static const unsigned long long MOD = (1ULL<<61) - 1;  // MOD=2^61-1

  int N;
  unsigned long long base = 10000000007;
  vector<unsigned long long> hash;
  vector<unsigned long long> power;

  // x mod MODを返す
  unsigned long long mod(unsigned long long x) {
    const unsigned long long MASK61 = MOD;
    unsigned long long xu = x>>61;
    unsigned long long xd = x & MASK61;
    unsigned long long ans = xu + xd;
    if (ans >= MOD) {
      ans -= MOD;
    }
    return ans;
  }
  
  // (a * b) mod MODを返す
  unsigned long long mul(unsigned long long a, unsigned long long b) {
    const unsigned long long MASK30 = (1ULL<<30) - 1;
    const unsigned long long MASK31 = (1ULL<<31) - 1;
    unsigned long long au = a>>31;
    unsigned long long ad = a & MASK31;
    unsigned long long bu = b>>31;
    unsigned long long bd = b & MASK31;
    unsigned long long mid = ad * bu + au * bd;
    unsigned long long midu = mid>>30;
    unsigned long long midd = mid & MASK30;
    unsigned long long ans = au * bu * 2 + midu + (midd<<31) + ad * bd;
#if 0  // 各A[i]が2^31以下であればmod無しで高速化可能
    ans = mod(ans);
#endif
    return ans;
  }

  // ランダムなbaseを決めたい時に使う。RollingHash::random_base()で呼ぶ
  static unsigned long long random_base() {
    time_t now = time(nullptr);
    mt19937_64 mt((unsigned long long)now);
    uniform_int_distribution<unsigned long long> dist(1ULL, MOD - 1);
    return dist(mt);
  }

  // 初期化 O(N)
  void build(const string &A) {
    N = A.size();
    hash.resize(N + 1, 0);
    power.resize(N + 1, 1);
    for (int n = 0; n < N; n++) {
      hash.at(n + 1) = mod(mul(hash.at(n), base) + A.at(n));
      power.at(n + 1) = mod(mul(power.at(n), base));
    }
  }

  // コンストラクタ
  RollingHash(const string &A, unsigned long long _base) : base(_base) { build(A); }
  RollingHash(const string &A) { RollingHash(A, random_base()); }

  // [a, b)のハッシュを取得 O(1)
  unsigned long long get(int a, int b) {  // 0-indexed
    const unsigned long long POSITIVIZER = MOD * 4;
    unsigned long long ans = mod(hash.at(b) + POSITIVIZER - mul(hash.at(a), power.at(b - a)));
    return ans;
  }
};

ostream& operator<<(ostream& os, const RollingHash rh) {
  os << "N=" << rh.N << endl;
  os << "base=" << rh.base << endl;
  const int MOD = -1;
  auto print = [&](const vector<unsigned long long> &v) {
    int N = v.size();
    os << '[';
    for (int i = 0; i < N; i++) {
      //os << "["<< i << "]=";
      os << v[i];
      if (i == N - 1) { continue; }
      else if (MOD > 0 && i % MOD == (MOD - 1)) { os << '\n'; }
      else { os << ' '; }
    }
    os << ']';
  };
  os << "hash=";
  print(rh.hash);
  os << endl;
  os << "power=";
  print(rh.power);
  return os;
}

const int INF = 1e9;

int main() {
  unsigned long long base = RollingHash::random_base();
  string S;
  cin >> S;
  int N = S.size();
  string T(S);
  reverse(T.begin(), T.end());
  RollingHash rh_s = RollingHash(S, base);
  RollingHash rh_t = RollingHash(T, base);
  int ans0_len = INF;
  string ans0;
  {  // 答が奇数の時
    for (int i = N / 2; i < N; i++) {  // i番目が中心と仮定
      int j = N - 1 - i;
      int len = j;
      int s0 = i - len;
      int t0 = 0;
      if (rh_s.get(s0, s0 + len) == rh_t.get(t0, t0 + len)) {
        ans0_len = i * 2 + 1;
        string tmp = S.substr(0, i);
        ans0 = tmp + S.at(i);
        reverse(tmp.begin(), tmp.end());
        ans0 += tmp;
        break;
      }
    }
  }
  int ans1_len = INF;
  string ans1;
  {  // 答が偶数の時
    for (int i = (N - 1) / 2; i < N; i++) {  // 左がi番目までと仮定
      int j = N - 1 - i;
      int len = j;
      int s0 = i - len + 1;
      int t0 = 0;
      if (rh_s.get(s0, s0 + len) == rh_t.get(t0, t0 + len)) {
        ans1_len = (i + 1) * 2;
        string tmp = S.substr(0, i + 1);
        ans1 = tmp;
        reverse(tmp.begin(), tmp.end());
        ans1 += tmp;
        break;
      }
    }
  }
  string ans;
  if (ans0_len < ans1_len) {
    ans = ans0;
  } else {
    ans = ans1;
  }
  cout << ans << endl;
  return 0;
}
