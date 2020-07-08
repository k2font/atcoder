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

    ll a = A * B;
    ll b = C * D;

    if(a > b) {
        cout << a << endl;
    } else if(a < b) {
        cout << b << endl;
    } else {
        cout << a << endl;
    }
}