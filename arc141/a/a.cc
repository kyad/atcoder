// https://atcoder.jp/contests/arc141/tasks/arc141_a

#include <iostream>
using namespace std;

string chmax(string S, string T) {
  if (stoll(S) > stoll(T)) {
    return S;
  } else {
    return T;
  }
}

string solve(string S) {
  int M = S.size();
  // 999...9
  string ans = "";
  for (int m = 0; m < M - 1; m++) {
    ans.push_back('9');
  }
  for (int p = 1; p <= M / 2; p++) {
    if (M % p != 0) {
      continue;
    }
    // Check unit unit unit ... is OK
    bool ok = true;
    string unit = S.substr(0, p);
    for (int i = 1; i < M / p; i++) {
      string now = S.substr(p * i, p);
      if (unit < now) {
        ok = true;
        break;
      } else if (unit > now) {
        ok = false;
        break;
      }
    }
    if (ok) {
      string now;
      for (int i = 0; i < M / p; i++) {
        now += unit;
      }
      ans = chmax(ans, now);
    }
    // Current ans is unit-1 unit-1 unit-1 ...
    long long u = stoll(unit);
    string unit2 = to_string(u - 1);
    if (unit2.size() == unit.size()) {
      string now;
      for (int i = 0; i < M / p; i++) {
        now += unit2;
      }
      ans = chmax(ans, now);
    } // else: 999...9
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    string S;
    cin >> S;
    string ans = solve(S);
    cout << ans << endl;
  }
  return 0;
}
