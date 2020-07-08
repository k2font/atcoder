#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> d(N); REP(i, N) cin >> d[i];

    sort(all(d));

    int cnt = 1;
    REP(i, N - 1) {
        if(d[i] < d[i + 1]) {
            cnt++;
        }
    }

    cout << cnt << endl;
}