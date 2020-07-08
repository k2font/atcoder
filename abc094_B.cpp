#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N, M, X; cin >> N >> M >> X;
    vector<int> A(M); REP(i, M) cin >> A[i];

    int cnt_A = 0;
    int cnt_B = 0;

    for(int i = 0; i < X; ++i) {
        if(i == 0) continue;
        for(int k = 0; k < M; ++k) {
            if(A[k] == i) cnt_A++;
        }
    }

    for(int i = X; i <= N; ++i) {
        if(i == 0) continue;
        for(int k = 0; k < M; ++k) {
            if(A[k] == i) cnt_B++;
        }
    }

    int res =  min(cnt_A, cnt_B);
    cout << res << endl;
}