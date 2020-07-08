#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

// 最大公約数
int gcd(int a, int b) {
   if (a%b == 0) {
       return(b);
   } else {
       return(gcd(b, a%b));
   }
}

// 最小公倍数
int lcm(int a, int b) {
   return a / gcd(a, b) * b;
}

int main(){
    ll N, X; cin >> N >> X;
    vector<ll> x(N); REP(i, N) cin >> x[i];

    ll res = pow(10, 9.0) + 7;

    sort(all(x));

    for(int i = 0; i < N; ++i) {
        int tmp = abs(X - x[i]);
        if(res > tmp) res = tmp;
    }

    for(int i = 0; i < N - 1; ++i) {
        ll a = abs(x[i] - x[i + 1]) % res;
        if(a != 0) {
            ll b = res % abs(x[i] - x[i + 1]);
            if(b == 0) {
                res = abs(x[i] - x[i + 1]);
            } else {
                res = gcd(abs(x[i] - x[i + 1]), res);
            }
        }
    }

    cout << res << endl;
}
