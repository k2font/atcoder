#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N; cin >> N;
    vector<ll> H(N); REP(i, N) cin >> H[i];

    string res = "";
    if(N == 1) {
        res = "Yes";
    } else {
        for(int i = N - 2; i >= 0; --i) {
            if(H[i] > H[i + 1]) {
                H[i]--;

                if(H[i] > H[i + 1]) {
                    res = "No";
                    break;
                }
            }

            if(i == 0) {
                res = "Yes";
            }
        }
    }

    cout << res << endl;
}