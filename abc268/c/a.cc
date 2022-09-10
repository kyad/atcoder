#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N, 0);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
  }
  vector<int> c(N, 0);
  for (int i = 0; i < N; i++) {
    int j = (P[i] - i + N) % N;
    c[j]++;
  }
  vector<int> d(N, 0);
  for (int i = 0; i < N; i++) {
    d[i] += c[(i - 1 + N) % N];
    d[i] += c[i];
    d[i] += c[(i + 1 + N) % N];
  }
  cout << *max_element(d.begin(), d.end()) << endl;
  return 0;
}
