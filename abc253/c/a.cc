#include <iostream>
#include <set>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  multiset<int> ms;
  for (int q = 0; q < Q; q++) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int X;
      cin >> X;
      ms.insert(X);
    } else if (mode == 2) {
      int X, C;
      cin >> X >> C;
      for (int c = 0; c < C; c++) {
        multiset<int>::iterator it = ms.find(X);
        if (it == ms.end()) {
          break;
        }
        ms.erase(it);
      }
    } else {
      int min = *ms.begin();
      int max = *(prev(ms.end()));
      cout << (max - min) << endl;
    }
  }
  return 0;
}
