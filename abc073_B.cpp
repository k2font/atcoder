#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> l(N), r(N); REP(i, N) cin >> l[i] >> r[i];

    int cnt = 0;
    REP(i, N) {
        for(int j = l[i]; j <= r[i]; ++j) {
            cnt++;
        }
    }

    cout << cnt << endl;
}