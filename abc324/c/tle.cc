#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

int main() {
  int N;
  string T;
  cin >> N >> T;
  vector<int> ans;

  auto solve = [&](string S) -> bool {
    // 1
    if (S == T) {
      return true;
    }
    // 2 Sに入れる
    int M = S.size();
    for (int m = 0; m <= M; m++) {
      for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        string str = "_";
        str[0] = c;
        string now(S);
        now.insert(m, str);
        if (now == T) {
          return true;
        }
      }
    }
    // 3 Sから削除
    for (int m = 0; m < M; m++) {
      string now(S);
      now.erase(m, 1);
      if (now == T) {
        return true;
      }
    }
    // 4 Sを1つ変える
    for (int m = 0; m < M; m++) {
      for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        string now(S);
        now[m] = c;
        if (now == T) {
          return true;
        }
      }
    }
    return false;
  };
  for (int n = 0; n < N; n++) {
    string S;
    cin >> S;
    if (solve(S)) {
      ans.push_back(n + 1);
    }
  }
  int K = ans.size();
  cout << K << endl;
  dumpvec(ans);
  return 0;
}
