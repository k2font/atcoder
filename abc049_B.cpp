#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int H, W; cin >> H >> W;
    vector<string> C(H); REP(i, H) cin >> C[i];

    vector<string> ne;

    REP(i, H) {
        // 2倍にするため、操作を2回実施する
        ne.push_back(C[i]);
        ne.push_back(C[i]);
    }

    REP(i, H * 2) {
        cout << ne[i] << endl;
    }
}