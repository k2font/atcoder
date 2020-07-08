#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}


int main() {
    int N; cin >> N;
    vector<ll> A(N); REP(i, N) cin >> A[i];
    map<ll, ll> tmp;

    REP(i, N) {
        if(tmp[A[i]] == 0) {
            tmp[A[i]]++;
        } else {
            tmp[A[i]]--;
        }
    }

    ll cnt = 0;
    sort(all(A));
    for(int i = 0; i < N; ++i) {
        if(i == 0) {
            if(tmp[A[i]] == 1) {
                cnt++;
            }
            continue;
        }

        if(A[i - 1] != A[i]) {
            if(tmp[A[i]] == 1) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}