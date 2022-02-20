#include <iostream>
#include <set>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> st;
  for (int n = 0; n < N; n++) {
    int a;
    cin >> a;
    st.insert(a);
  }
  cout << st.size() << endl;
  return 0;
}
