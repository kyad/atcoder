#include <iostream>
using namespace std;

int main() {
  int N, L, R;
  cin >> N >> L >> R;
  int g_all = 0;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    int g = A % (L + R);
    g /= L;
    g_all ^= g;
  }
  cout << (g_all > 0 ? "First" : "Second") << endl;
  return 0;
}
