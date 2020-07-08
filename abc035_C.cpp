#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N, Q; cin >> N >> Q;
    vector<int> l(Q), r(Q); REP(i, Q) cin >> l[i] >> r[i];

    // どの面も黒が上に向くように並んでいる
    vector<int> othello(N+1); REP(i, N+1) othello[i] = 0;

    REP(i, Q) {
        othello[l[i] - 1]++;
        othello[r[i]]--;
    }

    ll res = 0;
    REP(i, N) {
        res += othello[i];
        if(res % 2 == 1) {
            cout << 1;
        } else {
            cout << 0;
        }
    }

    cout << endl;
}