#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    ll N; cin >> N;

    if(N % 2 == 1) {
        cout << 0 << endl;
    } else {
        ll ans = 0;
        ll tmp = N / 2;
        while(tmp) {
            tmp = tmp / 5;
            ans += tmp;
        }
        cout << ans << endl;
    }
}