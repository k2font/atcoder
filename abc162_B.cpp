#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main() {
    ll N; cin >> N;
    vector<ll> ans(N+1);

    ans[0] = 0;
    for(ll i = 1; i <= N; ++i) {
        if(i % 3 == 0 && i % 5 == 0) {
            ans[i] = 0;
        } else if(i % 3 == 0) {
            ans[i] = 0;
        } else if(i % 5 == 0) {
            ans[i] = 0;
        } else {
            ans[i] = i;
        }
    }

    ll tmp = 0;
    for(int i = 0; i <= N; ++i) {
        tmp += ans[i];
    }
    cout << tmp << endl;
}