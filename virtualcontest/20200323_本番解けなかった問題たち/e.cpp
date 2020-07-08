#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    ll a, b, c; cin >> a >> b >> c;

    ll tmp1 = c - a - b;
    ll tmp2 = (c - a - b) * (c - a - b) - 4 * a * b;

    if(tmp1 >= 0 && tmp2 > 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}