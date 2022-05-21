#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  long long L;
  cin >> N >> L;
  multiset<long long> ms;
  long long sum = 0;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    ms.insert(A);
    sum += A;
  }
  if (sum != L) {
    ms.insert(L - sum);
  }
  long long ans = 0;
  while (ms.size() >= 2) {
    long long a = *ms.begin();
    ms.erase(ms.begin());
    long long b = *ms.begin();
    ms.erase(ms.begin());
    long long c = a + b;
    ms.insert(c);
    ans += c;
  }
  cout << ans << endl;
  return 0;
}
