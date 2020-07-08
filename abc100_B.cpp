#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int D; cin >> D;
    int N; cin >> N;

    ll res = pow(100, D) * N;

    if(D == 0 && N == 100) {
        cout << 101 << endl;
    } else if(D == 1 && N == 100) {
        cout << 10100 << endl;
    } else if(D == 2 && N == 100) {
        cout << 1010000 << endl;
    } else {
        cout << res << endl;
    }
}