#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N, D, X; cin >> N >> D >> X;
    vector<int> A(N); REP(i, N) cin >> A[i];

    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        for(int k = 0; k < D; k = k + A[i]) {
            cnt++;
        }
    }

    cout << X + cnt << endl;
}