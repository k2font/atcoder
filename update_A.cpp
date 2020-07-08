#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int S, L, R; cin >> S >> L >> R;

    if(S < L) {
        cout << L << endl;
    } else if(S > R) {
        cout << R << endl;
    } else {
        cout << S << endl;
    }
}