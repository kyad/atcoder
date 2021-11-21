// https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int n = 0; n < N; n++) {
    cin >> a.at(n);
  }
  const long long INF = 1000000000LL * 15 + 1;
  const long long MINF = 0;
  long long ans = INF;
  for (int bit = 0; bit < (1<<N); bit++) {
    int k = 0;
    long long sum = 0;
    long long prev = MINF;
    for (int b = 0; b < N; b++) {
      if ((bit >> b) & 1) {
        k++;
        long long cost = max(prev + 1 - a[b], 0LL);
        prev = a[b] + cost;
        sum += cost;
      } else {
        prev = max(prev, (long long)a[b]);
      }
    }
    if (k < K) {
      continue;
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
  
