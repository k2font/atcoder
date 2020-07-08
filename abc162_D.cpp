#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main() {
    int N; cin >> N;
    string S; cin >> S;

    ll R = 0;
    ll G = 0;
    ll B = 0;
    ll tmp_R = 0;
    ll tmp_G = 0;
    ll tmp_B = 0;
    REP(i, N) {
        if(S[i] == 'R') R++;
        if(S[i] == 'G') G++;
        if(S[i] == 'B') B++;
    }

    ll cnt = 0;

    for(int i = 0; i < N - 2; ++i) {
        tmp_R = R;
        tmp_G = G;
        tmp_B = B;
        for(int j = i + 1; j < N - 1; ++j) {
            if((S[i] == 'R' && S[j] == 'G') || (S[i] == 'G' && S[j] == 'R')) {
                if(j + (j - i) < N && S[j + (j - i)] == 'B') {
                    cnt = cnt + tmp_B - 1;
                } else {
                    cnt = cnt + tmp_B;
                }
            } else if((S[i] == 'R' && S[j] == 'B') || (S[i] == 'B' && S[j] == 'R')) {
                if(j + (j - i) < N && S[j + (j - i)] == 'G') {
                    cnt = cnt + tmp_G - 1;
                } else {
                    cnt = cnt + tmp_G;
                }
            } else if((S[i] == 'B' && S[j] == 'G') || (S[i] == 'G' && S[j] == 'B')) {
                if(j + (j - i) < N && S[j + (j - i)] == 'R') {
                    cnt = cnt + tmp_R - 1;
                } else {
                    cnt = cnt + tmp_R;
                }
            }

            if(S[j] == 'R') tmp_R--;
            if(S[j] == 'G') tmp_G--;
            if(S[j] == 'B') tmp_B--;
        }

        if(S[i] == 'R') R--;
        if(S[i] == 'G') G--;
        if(S[i] == 'B') B--;
    }

    cout << cnt << endl;
}