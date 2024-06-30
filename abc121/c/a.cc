#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int> > AB(N);
  for (int i = 0; i < N; i++) {
    cin >> AB[i].first >> AB[i].second;
  }

  // 栄養ドリンクが安い順に並び換える
  sort(AB.begin(), AB.end());

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    long long a = AB[i].first;
    int b = AB[i].second;
    int x = min(b, M);  // 今買う本数
    M -= x;
    long long now = a * x;
    ans += now;
  }

  cout << ans << endl;
  return 0;
}
