#include <iostream>
#include <set>
using namespace std;

int main() {
  set<int> s;
  for (int i = 0; i < 5; i++) {
    int A;
    cin >> A;
    s.insert(A);
  }
  cout << s.size() << endl;
  return 0;
}
