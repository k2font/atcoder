#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

bool IsPrime(ll num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main(){
    ll N; cin >> N;

    ll cnt = 0;
    ll result = 1000000000007; // 10^12+7
    double sqrtNum = sqrt(N);

    if(IsPrime(N) == true) {
        result = N - 1;
    } else {
        for(int i = 2; i <= sqrtNum; ++i) {
            if(N % i == 0) {
                cnt = (N / i) + i - 2;
                if(result > cnt) {
                    result = cnt;
                }
            }
        }
    }

    cout << result << endl;
}