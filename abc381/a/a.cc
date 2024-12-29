#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    if (N % 2 == 0) {
        cout << "No" << endl;
        return 0;
    }
    int s = N / 2;  // スラッシュの位置
    for (int i = 0; i < s; i++) {
        if (S.at(i) != '1') {
            cout << "No" << endl;
            return 0;
        }
    }
    if (S.at(s) != '/') {
        cout << "No" << endl;
        return 0;
    }
    for (int i = s + 1; i < N; i++) {
        if (S.at(i) != '2') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}