#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
  int M = 3;
  vector<vector<long long> > A(M, vector<long long>(M));
  for (int y = 0; y < M; y++) {
    for (int x = 0; x < M; x++) {
      cin >> A[y][x];
    }
  }

  const int M2 = M * M;
  int num = 1;
  for (int i = 0; i < M2; i++) {
    num *= 3;
  }
  auto encode = [&](const vector<vector<int> > &S) {
    int ans = 0;
    for (int i = 0; i < 9; i++) {
      ans *= 3;
      int y = i / M;
      int x = i % M;
      ans += S[y][x];
    }
    return ans;
  };
  auto decode = [&](int z) -> vector<vector<int> > {
    vector<vector<int> > S(M, vector<int>(M));
    for (int j = 0; j < 9; j++) {
      int i = 8 - j;
      int y = i / M;
      int x = i % M;
      S[y][x] = z % 3;
      z /= 3;
    }
    return S;
  };

  auto check = [&](int player, const vector<vector<int> > &S) -> bool {
    // 横
    for (int y = 0; y < M; y++) {
      bool ok = true;
      for (int x = 0; x < M; x++) {
        if (S[y][x] != player) {
          ok = false;
          break;
        }
      }
      if (ok) {
        return true;
      }
    }
    // 縦
    for (int x = 0; x < M; x++) {
      bool ok = true;
      for (int y = 0; y < M; y++) {
        if (S[y][x] != player) {
          ok = false;
          break;
        }
      }
      if (ok) {
        return true;
      }
    }
    // 斜め
    if (S[0][0] == player && S[1][1] == player && S[2][2] == player) {
      return true;
    }
    if (S[0][2] == player && S[1][1] == player && S[2][0] == player) {
      return true;
    }
    return false;
  };

  vector<int> memo(num, -1);  // 0: 高橋くんが勝ち、1: 青木くんが勝ち
  auto f = [&](auto f, int player, int z) {  // z: 盤面
    if (memo[z] >= 0) {
      return memo[z];
    }
    vector<vector<int> > S = decode(z);
    for (int i = 0; i < 2; i++) {
      if (check(i, S)) {
        memo[z] = i;
        return i;
      }
    }
    bool found = false;  // 次の有効手が見つかったかどうか
    for (int y = 0; y < M; y++) {
      for (int x = 0; x < M; x++) {
        if (S[y][x] == 2) {  // 有効手あり
          vector<vector<int> > nS(S);
          found = true;
          nS[y][x] = player;
          int nz = encode(nS);
          int next = f(f, 1 - player, nz);
          if (next == player) {  // 自分の勝ち確があれば自分が勝ち
            memo[z] = player;
            return player;
          }
        }
      }
    }
    if (found) {  // 自分の勝ち確が一つもなければ相手が勝ち
      memo[z] = 1 - player;
      return 1 - player;
    }
    // 得点勝負(末端の場合)
    vector<long long> score(2, 0);
    for (int y = 0; y < M; y++) {
      for (int x = 0; x < M; x++) {
        assert(S[y][x] != 2);
        score.at(S[y][x]) += A[y][x];
      }
    }
    if (score[0] > score[1]) {
      memo[z] = 0;
      return 0;
    } else if (score[0] < score[1]) {
      memo[z] = 1;
      return 1;
    } else {
      assert(false);
    }
  };

  vector<vector<int> > S0(M, vector<int>(M, 2));  // 初期状態
  int z0 = encode(S0);
  int ans = f(f, 0, z0);

  vector<string> name;
  name.push_back("Takahashi");
  name.push_back("Aoki");
  cout << name[ans] << endl;
  return 0;
}
