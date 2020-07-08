#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    ll A, B, K; cin >> A >> B >> K;

    ll cnt = 0;
    while(true) {
        if(A % 2 == 1) {
            A--;
        }
        B = B + A / 2;
        A = A / 2;
        cnt++;

        if(K == cnt) {
            break;
        }

        if(B % 2 == 1) {
            B--;
        }
        A = A + B / 2;
        B = B / 2;
        cnt++;

        if(K == cnt) {
            break;
        }
    }

    cout << A << " " << B << endl;
}