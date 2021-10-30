#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> count(N, 0);
  for (int n = 0; n < N - 1; n++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    count.at(a)++;
    count.at(b)++;
  }
  for (int n = 0; n < N; n++) {
    if (count.at(n) == N - 1) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
