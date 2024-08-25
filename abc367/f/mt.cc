#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

random_device seed_gen;
mt19937_64 rnd(seed_gen());

const unsigned long long MOD = (1ULL << 61) - 1;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N + 1, 1);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
  }
  vector<int> B(N + 1, 1);
  for (int i = 1; i <= N; i++) {
    cin >> B.at(i);
  }
  // ハッシュ
  vector<unsigned long long> hash(N + 1);
  for (int i = 0; i <= N; i++) {
    hash.at(i) = rnd() % MOD;
  }
  // 累積和
  vector<unsigned long long> U(N + 1, 0);
  vector<unsigned long long> V(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    U.at(i) = (U.at(i - 1) + hash.at(A.at(i))) % MOD;
    V.at(i) = (V.at(i - 1) + hash.at(B.at(i))) % MOD;
  }
  for (int qi = 0 ; qi < Q; qi++) {
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    if (l - r != L - R) {
      cout << "No" << '\n';
      continue;
    }
    unsigned long long u = (U.at(r) - U.at(l - 1) + MOD) % MOD;
    unsigned long long v = (V.at(R) - V.at(L - 1) + MOD) % MOD;
    bool ans = u == v;
    cout << (ans ? "Yes" : "No") << '\n';
  }

  return 0;
}
