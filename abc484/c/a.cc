#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
  }
  int l = 0, r = N - 1;
  while (l <= N - 1) {
    if (A.at(l) == B.at(l)) {
      l++;
    } else {
      break;
    }
  }
  while (r >= 0) {
    if (A.at(r) == B.at(r)) {
      r--;
    } else {
      break;
    }
  }
  if (l > r) {
    cout << "Yes" << endl;
    return 0;
  } else if (l == r) {
    cout << "No" << endl;
    return 0;
  }
  string ans = "No";
  {
    bool ok = true;
    for (int i = l; i <= r - 1; i++) {
      if (A.at(i) == B.at(i + 1)) {
        // ok
      } else {
        ok = false;
      }
    }
    if (A.at(r) == B.at(l)) {
      // ok
    } else {
      ok = false;
    }
    if (ok) {
      ans = "Yes";
    }
  }
  {
    bool ok = true;
    for (int i = l; i <= r - 1; i++) {
      if (A.at(i + 1) == B.at(i)) {
        //ok
      } else {
        ok = false;
      }
    }
    if (A.at(l) == B.at(r)) {
      // ok
    } else {
      ok = false;
    }
    if (ok) {
      ans = "Yes";
    }
  }
  cout << ans << '\n';
  return 0;
}
