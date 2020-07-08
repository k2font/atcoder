#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    ll N, K; cin >> N >> K;
    vector<ll> H(N); REP(i, N) cin >> H[i];

    sort(all(H));

    ll res = 0;
    for(int i = N - 1; i >= 0; --i) {
        if(K==0) {
            res = accumulate(all(H), 0LL);
            break;
        }

        H[i] = 0;
        K--;
    }

    cout << res << endl;
}