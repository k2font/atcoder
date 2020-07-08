#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N; cin >> N;
    string S1, S2; cin >> S1 >> S2;

    ll res = 1;
    int cnt = 0;
    ll MOD = 1000000007;

    REP(i, N){
        if(cnt != 0) {
            cnt--;
            continue;
        } else {
            if(S1[i] == S2[i]) {
                if(S1[i + 1] == S2[i + 1]) {
                    res = (res * 6) % MOD;
                    cnt = 1;
                } else {
                    res = (res * 6) % MOD;
                    cnt = 2;
                }
            } else if(S1[i] != S2[i]) {
                if(S1[i + 2] == S2[i + 2]) {
                    res = (res * 6) % MOD;
                    cnt = 2;
                } else {
                    res = (res * 6) % MOD;
                    cnt = 3;
                }
            }
        }
    }

    cout << res << endl;
}