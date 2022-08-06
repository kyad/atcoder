#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> count(14, 0);
  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;
  count[A]++;
  count[B]++;
  count[C]++;
  count[D]++;
  count[E]++;
  bool have2 = false;
  bool have3 = false;
  for (int i = 1; i <= 13; i++) {
    if (count[i] == 2) {
      have2 = true;
    } else if (count[i] == 3) {
      have3 = true;
    }
  }
  if (have2 && have3) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
