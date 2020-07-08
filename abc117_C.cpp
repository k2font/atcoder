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
    vector<int> X(M); REP(i, M) cin >> X[i];

    if(M == 1 || N >= M) {
        cout << 0 << endl;
    } else {
        sort(all(X));
        vector<ll> minus(M - 1);

        for(int i = 0; i < M - 1; ++i) {
            minus[i] = abs(X[i + 1] - X[i]);
        }

        sort(all(minus), greater<int>());

        ll res = X.at(M - 1) - X.at(0);
        for(int i = 0; i < N - 1; ++i) {
            res -= minus.at(i);
        }

        cout << res << endl;
    }
}