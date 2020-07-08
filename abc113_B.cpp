#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N, T, A; cin >> N >> T >> A;
    vector<int> H(N); REP(i, N) cin >> H[i];

    double res = 10000007.0;
    int result = 0;
    REP(i, N) {
        double cnt = abs(A - (T - H[i] * 0.006));
        if(res > cnt) {
            res = cnt;
            result = i + 1;
        }
    }

    cout << result << endl;
}