#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

ll d(ll _num) {
    ll cnt = 0;
    while(_num) {
        _num = _num / 10;
        cnt++;
    }
    return cnt;
}

int main(){
    ll A, B, X; cin >> A >> B >> X;

    ll judge = pow(10, 9.0) + 1;
    ll judge_low = 0;
    while(judge - judge_low > 1) {
        ll mid = (judge_low + judge) / 2;
        ll C = A * mid + B * d(mid);
        if(C <= X) {
            judge_low = mid;
        } else {
            judge = mid;
        }
    }

    cout << judge_low << endl;
}