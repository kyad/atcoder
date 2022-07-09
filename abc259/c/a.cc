#include <iostream>
#include <vector>
using namespace std;

vector<pair<char, int> > solve(string S) {
  vector<pair<char, int> > ans;
  char now = S[0];
  int count = 1;
  for (size_t i = 1; i < S.size(); i++) {
    if (S[i] == now) {
      count++;
      continue;
    }
    ans.push_back(make_pair(now, count));
    now = S.at(i);
    count = 1;
  }
  ans.push_back(make_pair(now, count));
  return ans;
}

// pair
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

// vector
template<class T> ostream& operator<<(ostream& os, const vector<T> &v) {
  size_t N = v.size();
  int MOD = -1;
  os << '[';
  for (size_t i = 0; i < N; i++) {
    os << v[i];
    if (i == N - 1) {
      continue;
    } else if (MOD > 0 && i % MOD == (MOD - 1)) {
      os << '\n';
    } else {
      os << ' ';
    }
  }
  os << ']';
  return os;
}

int main() {
  string S, T;
  cin >> S;
  cin >> T;
  vector<pair<char, int> > s = solve(S);
  vector<pair<char, int> > t = solve(T);
  bool ans = false;
  if (s.size() == t.size()) {
    ans = true;
    for (int i = 0; i < s.size(); i++) {
      if (s[i].first != t[i].first) {
        ans = false;
        break;
      }
      if (s[i].second == 1) {
        if (t[i].second != 1) {
          ans = false;
          break;
        }
      } else {
        if (t[i].second < s[i].second) {
          ans = false;
          break;
        }
      }
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
