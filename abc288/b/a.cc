#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<string> S(K);
  for (int n = 0; n < N; n++) {
    if (n < K) {
      cin >> S.at(n);
    } else {
      string s;
      cin >> s;
    }
  }
  sort(S.begin(), S.end());
  for (string s : S) {
    cout << s << '\n';
  }
  return 0;
}
