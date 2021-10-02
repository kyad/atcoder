#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<long long, int> imos;
  for (int n = 0; n < N; n++) {
    long long A, B;
    cin >> A >> B;
    imos[A]++;
    imos[A + B]--;
  }
  int prev = 0;
  for (map<long long, int>::iterator it = imos.begin(); it != imos.end(); it++) {
    it->second += prev;
    prev = it->second;
  }
  vector<int> ans(N + 1, 0);
  for (map<long long, int>::iterator it = imos.begin(); it != imos.end(); it++) {
    if (it->second == 0) {
      continue;
    }
    ans[it->second] += (next(it)->first - it->first);
  }
  for (int n = 1; n <= N; n++) {
    cout << ans.at(n) << (n == N ? '\n' : ' ');
  }
  return 0;
}
