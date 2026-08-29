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
  vector<int> count(101, 0);
  for (int i = 0; i < N; i++) {
    count.at(A.at(i))++;
  }
  int ans = 0;
  for (int a = 1; a <= 100; a++) {
    int c = count.at(a) % 2;
    int now = a * c;
    ans += now;
  }
  cout << ans << '\n';
  return 0;
}
