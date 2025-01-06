#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<tuple<int, int, int> > LR(N);
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        LR[i] = make_tuple(l, r, i);
    }
    sort(LR.begin(), LR.end());
    long long Lsum = 0;
    for (int i = 0; i < N; i++) {
        Lsum += get<0>(LR[i]);
    }
    long long delta_sum = 0;
    for (int i = 0; i < N; i++) {
        int L = get<0>(LR[i]);
        int R = get<1>(LR[i]);
        delta_sum += R - L;
    }
    if (Lsum > 0) {
        cout << "No" << endl;
        return 0;
    }
    if (Lsum + delta_sum < 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    long long diff = -Lsum;
    vector<long long> X(N, -1);
    for (int i = 0; i < N; i++) {
        long long L = get<0>(LR[i]);
        long long R = get<1>(LR[i]);
        int idx = get<2>(LR[i]);
        long long add = min(R - L, diff);
        X.at(idx) = L + add;
        diff -= add;
    }
    for (int i = 0; i < N; i++) {
        cout << X.at(i) << " \n"[i == N - 1];
    }
    return 0;    
}