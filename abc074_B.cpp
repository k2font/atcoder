#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    double N, K; cin >> N >> K;
    vector<int> x(N); REP(i, N) cin >> x[i];

    int res = 0;

    REP(i, N) {
        if(x[i] <= abs(x[i] - K)) {
            res += x[i];
        } else if(x[i] >= abs(x[i] - K)) {
            res += abs(x[i] - K);
        }
    }

    cout << res * 2 << endl;
}