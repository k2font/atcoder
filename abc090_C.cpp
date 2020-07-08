#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    ll N, M; cin >> N >> M;
    if(N == 1 && M == 1) {
        cout << 1 << endl;
    } else if(N == 1 || M == 1) {
        if(N == 1) cout << M - 2 << endl;
        if(M == 1) cout << N - 2 << endl;
    } else {
        ll res = (N - 2) * (M - 2);
        cout << res << endl;
    }
}