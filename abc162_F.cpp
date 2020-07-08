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

    sort(all(A));

    ll ans = 0;
    ll cnt = 0;
    ll brek = N / 2;
    for(int i = N - 1; i >= 0; i = i - 2) {
        ans += A[i];
        cnt++;
        if(brek == cnt) {
            break;
        }
    }

    cout << ans << endl;
}