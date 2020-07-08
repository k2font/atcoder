#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

int main(){
    int N, K; cin >> N >> K;
    vector<int> A(N); REP(i, N) cin >> A[i];

    sort(all(A));

    vector<pair<int, int>> mp(N);

    // 種類数
    int cnt = 0;
    int req = 0;
    for(int i = 1; i <= N; ++i) {
        req++;
        if(A[i - 1] != A[i]) {
            // map型変数にある値と個数を突っ込む
            mp[cnt] = make_pair(req, A[i - 1]);
            req = 0; // 個数カウンタを初期化
            cnt++; // 種類数カウンタをインクリメント
        }
    }

    sort(mp.begin(), mp.end(), comp); // 個数をキーにソート

    if(cnt <= K) {
        cout << 0 << endl;
    } else {
        int result = 0;
        for(int i = 0; i < N; ++i) {
            if(mp[i].first == 0) continue;
            cnt--;
            result = result + mp[i].first;
            if(cnt <= K) {
                cout << result << endl;
                break;
            }
        }
    }
}
