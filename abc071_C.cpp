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
    for(int i = 0; i < N; ++i) {
        tmp[A[i]]++;
    }

    ll a = 0;
    ll b = 0;
    sort(all(A));
    for(int i = N - 1; i >= 0; --i) {
        if(tmp[A[i]] >= 2) {
            if(a == 0) {
                a = A[i];
                if(tmp[A[i]] >= 4) {
                    b = A[i];
                    break;
                }
            }

            if(a != 0 && a != A[i] && b == 0) {
                b = A[i];
                break;
            }
        }
    }

    ll c = a * b;
    cout << c << endl;
}