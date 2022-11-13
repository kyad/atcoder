#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  long long N, M;
  cin >> N >> M;
  vector<long long> A(N);
  long long sum = 0;
  map<long long, int> count;
  for (int n = 0; n < N; n++) {
    long long a;
    cin >> a;
    A.at(n) = a;
    sum += a;
    count[a]++;
  }
  //print(A, sum, count);
  long long mx = 0;
  vector<bool> counted(M, false);
  for (auto [a, cnt] : count) {
    if (counted[a]) {
      continue;
    }
    long long now = 0;
    counted[a] = true;
    now += a * cnt;
    for (int i = 1; i < N; i++) {
      long long b = (a + i) % M;
      if (count.count(b) == 0) {
        break;
      }
      now += b * count[b];
      counted[b] = true;
    }
    mx = max(mx, now);
  }
  long long ans = sum - mx;
  cout << ans << endl;
  return 0;
}
