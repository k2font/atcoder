#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N, K; cin >> N >> K;
    int R, S, P; cin >> R >> S >> P;
    string T; cin >> T;

    vector<char> cnt(N);

    ll res = 0;
    for(int i = 0; i < N; ++i) {
        ll ans = 0;
        if(T[i] == 'r') {
            cnt[i] = 'p';
            ans = P;
        } else if(T[i] == 's') {
            cnt[i] = 'r';
            ans = R;
        } else if(T[i] == 'p') {
            cnt[i] = 's';
            ans = S;
        }

        if(i >= K) {
            if(cnt[i - K] == cnt[i]) {
                cnt[i] = 'a';
                ans = 0;
            }
        }
        res += ans;
        // cout << cnt[i] << " " << cnt[i - K] << " " << (cnt[i] == cnt[i - K]) << " " << T[i] << endl;
        // cout << res << endl;
    }

    cout << res << endl;
}