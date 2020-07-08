#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> h(N); REP(i, N) cin >> h[i];

    vector<vector<int>> h_tmp(N, vector<int>(101));
    REP(i, N) {
        REP(k, 101) {
            if(k < h[i]) {
                h_tmp[i][k] = 1;
            } else {
                h_tmp[i][k] = 0;
            }
        }
    }

    int cnt = 0;
    REP(i, 101) {
        REP(k, N) {
            if(k == 0 && h_tmp[k][i] == 1) {
                cnt++;
            }
            
            if(k != 0 && h_tmp[k - 1][i] < h_tmp[k][i]) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}