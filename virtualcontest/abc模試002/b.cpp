#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int A, B, C, D; cin >> A >> B >> C >> D;

    int cnt = 0;
    int res = 0;

    REP(i, 101) {
        if(i == A) {
            cnt++;
        }

        if(i == C) {
            cnt++;
        }

        if(i == B || i == D) {
            cnt--;
        }

        if(cnt == 2) {
            res++;
        }
    }

    cout << res << endl;
}