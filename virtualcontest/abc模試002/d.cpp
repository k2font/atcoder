#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int N; cin >> N;
    const int MAX = 100000;
    ll dp[MAX];
    const ll INF = 1000000007;
    REP(i, N) dp[i] = INF;

    dp[0] = 0;
    REP(i, MAX) {
        if(i >= 1) chmin(dp[i], dp[i - 1] + 1);
        if(i >= 6) chmin(dp[i], dp[i - 6] + 1);
        if(i >= 9) chmin(dp[i], dp[i - 9] + 1);
    }

    cout << dp[N - 1] << endl;
}