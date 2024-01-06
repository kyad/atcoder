#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  for (int x = 0; x <= N; x++) {
    for (int y = 0; y <= N; y++) {
      for (int z = 0; z <= N; z++) {
        if (x + y + z > N) {
          continue;
        }
        cout << x << ' ' << y << ' ' << z << '\n';
      }
    }
  }

  return 0;
}
