#include <iostream>
#include <vector>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

int main() {
  long long N, M;
  cin >> N >> M;
  // (1, 1)から(i, j)までの和を返す。i==0||j==0の時は0を返す。
  auto sum = [&](int i, int j) -> mint {
    if (i == 0 || j == 0) {
      return mint(0);
    }
    // S1
    mint S1, dS1;
    {
      mint jj;
      if (j % 2) {
        jj = j;
      } else {
        jj = j - 1;
      }
      mint num = (jj + 1) / 2;
      S1 = num * num;
      dS1 = num * 2 * M;
    }
    // S2
    mint S2, dS2;
    {
      mint jj;
      if (j % 2) {
        jj = j - 1;
      } else {
        jj = j;
      }
      mint num = jj / 2;
      S2 = M * num + num * (num + 1);
      dS2 = num * 2 * M;
    }
    // sum
    mint nS1, nS2;
    if (i % 2) {
      nS1 = (i + 1) / 2;
      nS2 = (i - 1) / 2;
    } else {
      nS1 = nS2 = i / 2;
    }
    mint ans = S1 * nS1 + dS1 * (nS1 - 1) * nS1 / 2
      + S2 * nS2 + dS2 * (nS2 - 1) * nS2 / 2;
    return ans;
  };

  
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    mint ans = sum(B, D) - sum(B, C - 1) - sum(A - 1, D) + sum(A - 1, C - 1);
    cout << ans.val() << '\n';
  }
  return 0;
}
