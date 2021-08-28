#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  bitset<8> a(A);
  bitset<8> b(B);
  bitset<8> c;
  c = (a ^ b);
  cout << c.to_ullong() << endl;
  return 0;
}
