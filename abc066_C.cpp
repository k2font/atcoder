#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int n; cin >> n;
    vector<ll> a(n); REP(i, n) cin >> a[i];

    deque<ll> b;

    int cnt = 0;
    while(true) {
        if(cnt % 2 == 0) {
            b.push_back(a[cnt]);
        } else {
            b.push_front(a[cnt]);
        }
        cnt++;

        if(cnt == n) {
            if(cnt % 2 == 0) {

            } else {
                reverse(all(b));
            }
            break;
        }
    }

    REP(i, n) cout << b[i] << " ";
    cout << endl;
}