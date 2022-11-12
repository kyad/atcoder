#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  long long N, M;
  cin >> N >> M;
  map<long long, long long> count;
  long long all = 0;
  for (long long n = 0; n < N; n++) {
    long long a;
    cin >> a;
    count[a]++;
    all += a;
  }
  long long mx = 0;
  long long now0 = 0;
  vector<bool> checked(M, false);
  for (map<long long, long long>::iterator it = count.begin(); it != count.end(); it++) {
    long long a = it->first;
    if (checked[a]) {
      continue;
    }
    long long cnt = it->second;
    long long now = a * cnt;
    map<long long, long long>::iterator j = next(it);
    long long prev_a = a;
    while (true) {
      long long a = j->first;
      long long cnt = j->second;
      // check next
      if (j == count.end()) {
        if (prev_a == M - 1) {
          now += now0;
        }
        break;
      }
      if (prev_a + 1 != a) {
        break;
      }
      checked[a] = true;
      prev_a = a;
      now += a * cnt;
      j = next(j);
    }
    mx = max(mx, now);
    if (a == 0) {
      now0 = now;
    }
  }
  long long ans = all - mx;
  cout << ans << endl;
  return 0;
}
