#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  long long T = 0;
  for (int i = 0; i < N; i++) {
    long long C;
    cin >> S.at(i) >> C;
    T += C;
  }
  sort(S.begin(), S.end());
  string ans = S.at(T % N);
  cout << ans << endl;
  return 0;
}
