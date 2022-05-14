#include <iostream>
#include <set>
#include <vector>
using namespace std;

// set
template<class T> ostream& operator<<(ostream& os, const set<T> &s) {
  os << '[';
  if (s.size() > 0) {
  typename set<T>::iterator last = s.end();
  last--;
  for (typename set<T>::iterator it = s.begin(); it != s.end(); it++) {
    os << *it;
    if (it != last) {
      os << ' ';
    }
  }
  }
  os << ']';
  return os;
}

int main() {
  int W;
  cin >> W;
  const int MAX = 1000000;
  //const int MAX = 20;
  set<int> S, T1, T2, T3;
  for (int n = 1; n <= MAX; n++) {
#if 0
    cout << "n="<<n<<endl;
    cout << "S="<<S<<endl;
    cout << "T1="<<T1<<endl;
    cout << "T2="<<T2<<endl;
    cout << "T3="<<T3<<endl;
#endif
    if (T1.count(n) > 0 || T2.count(n) > 0 || T3.count(n) > 0) {
      continue;
    }
    // Add n
    //cout << "Add n="<<n<<endl;
    S.insert(n);
    // Add to T3
    for (set<int>::iterator it = T2.begin(); it != T2.end(); it++) {
      int now = *it;
      int next = now + n;
      if (next > MAX) {
        continue;
      }
      T3.insert(next);
    }
    // Add to T2
    for (set<int>::iterator it = T1.begin(); it != T1.end(); it++) {
      int now = *it;
      int next = now + n;
      if (next > MAX) {
        continue;
      }
      T2.insert(next);
    }
    // Add to T1;
    T1.insert(n);
  }
  cout << S.size() << endl;
  return 0;
}
