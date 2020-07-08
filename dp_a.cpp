#include <bits/stdc++.h>
using namespace std;

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

const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    vector<long long> h(N);
    for(int i = 0; i < N; ++i) cin >> h[i];

    vector<long long> dp(100010);
    for(int i = 0; i < dp.size(); ++i) dp[i] = INF; // すべてのdpテーブルにINFを代入する

    dp[0] = 0; // 初期条件
    for(int i = 1; i < N; ++i) {
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if(i > 1) chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}