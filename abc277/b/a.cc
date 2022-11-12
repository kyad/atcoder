#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<char> suits;
  set<char> num;
  set<string> cards;
  suits.insert('H');
  suits.insert('D');
  suits.insert('C');
  suits.insert('S');
  num.insert('A');
  for (int i = 2; i <= 9; i++) {
    num.insert('0' + i);
  }
  num.insert('T');
  num.insert('J');
  num.insert('Q');
  num.insert('K');
  bool ans = true;
  for (int n = 0; n < N; n++) {
    string S;
    cin >> S;
    if (suits.count(S[0]) == 0 || num.count(S[1]) == 0 || cards.count(S) > 0) {
      ans = false;
    }
    cards.insert(S);
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
