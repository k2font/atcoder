#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    ll X; cin >> X;

    ll res = 0;
    while(X >= 500) {
        X = X - 500;
        res += 1000;
    }

    while(X >= 5) {
        X = X - 5;
        res += 5;
    }

    cout << res << endl;
}