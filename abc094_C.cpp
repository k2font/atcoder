#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N; cin >> N;
    vector<ll> X(N); REP(i, N) cin >> X[i];
    vector<ll> X_tmp(N); X_tmp = X;

    sort(all(X_tmp));

    int cnt = N / 2;
    int hantei = X_tmp[cnt];
    for(int i = 0; i < N; ++i) {
        if(X[i] < hantei) {
            cout << X_tmp[cnt] << endl;
        } else {
            cout << X_tmp[cnt - 1] << endl;
        }
    }
}