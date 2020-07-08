#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
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

int main() {
    int K; cin >> K;

    ll ans = 0;
    REP(i, K) {
        REP(j, K) {
            ll tmp = 0;
            tmp = gcd(i, j);
            REP(m, K) {
                ans = ans + gcd(tmp, m);
            }
        }
    }

    cout << ans << endl;
}