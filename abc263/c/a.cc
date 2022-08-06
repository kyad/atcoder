#include <iostream>
#include <vector>
using namespace std;

int M;
void f(int s, int n, vector<int>& pre) {
  if (n == 0) {
    for (size_t i = 0; i < pre.size(); i++) {
      //cout << pre[i] << (i == pre.size() - 1 ? '\n' : ' ');
      cout << pre[i] << ' ';
    }
    cout << endl;
    return;
  }
  for (int i = s; i <= M - n + 1; i++) {
    vector<int> a(pre);
    a.push_back(i);
    f(i + 1, n - 1, a);
  }
}

int main() {
  int N;
  cin >> N >> M;
  vector<int> pre;
  f(1, N, pre);
  return 0;
}
