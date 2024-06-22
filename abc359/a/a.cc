#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    if (S == "Takahashi") {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
