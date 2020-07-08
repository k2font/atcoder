#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

const int INF = 1000000007;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main(){
    int H, W; cin >> H >> W;

    vector<string> S(H); rep(i, H) cin >> S[i]; // スタート

    // dpテーブルの初期化
    long long dp[H * W][H * W];
    for(int i = 0; i < H * W; ++i) {
        for(int j = 0; j < H * W; ++j) {
            dp[i][j] = INF;
        }
    }
     
    // グラフをつくる
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            // あるマスが「.」の場合、4方向を見る
            if(S[i][j] == '.') {
                for(int k = 0; k < 4; ++k) { // あるマスの4方向を確認する
                    if(i + dy[k] < 0 || j + dx[k] < 0 || i + dy[k] >= H || j + dx[k] >= W) {
                        continue;
                    }

                    if(S[i + dy[k]][j + dx[k]] == '#') {
                        continue;
                    }

                    dp[ i * W + j ][ (i + dy[k]) * W + (j + dx[k]) ] = 1;
                    dp[ (i + dy[k]) * W + (j + dx[k]) ][ i * W + j ] = 1;
                }
            }
        }
    }

    // ワーシャルフロイド法
    for (int k = 0; k < H * W; k++){       // 経由する頂点
        for (int i = 0; i < H * W; i++) {    // 始点
            for (int j = 0; j < H * W; j++) {  // 終点
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                if(i == j) {
                    dp[i][j] = 0;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < H * W; ++i) {
        for(int j = 0; j < H * W; ++j) {
            if(dp[i][j] != INF) {
                if(ans < dp[i][j]) {
                    ans = dp[i][j];
                }
            }
        }
    }

    /*
    for(int i = 0; i < H * W; ++i) {
        for(int j = 0; j < H * W; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    } */

    cout << ans << endl;
}