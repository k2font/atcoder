#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N, x; cin >> N >> x;
    vector<int> a(N); REP(i, N) cin >> a[i];

    sort(all(a));

    int cnt = 0;
    REP(i, N) {
        if(x <= 0 || a[i] > x) {
            break;
        } else {
            cnt++;
            x = x - a[i];
        }

        if(i == N - 1) {
            if(x > 0) {
               cnt--; 
            }
        }
    }

    cout << cnt << endl;
}