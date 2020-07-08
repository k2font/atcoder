#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    string S; cin >> S;
    int cnt = 0;

    REP(i, S.size()) {
        if(i == 0) continue;

        if(S[i] != S[i - 1]) {
            continue;
        } else if(S[i] == S[i - 1]) {
            if(S[i] == '0') {
                S[i] = '1';
            } else {
                S[i] = '0';
            }
            cnt++;
        }
    }

    cout << cnt << endl;
}