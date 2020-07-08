#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int H, W, N; cin >> H >> W >> N;
    vector<int> h(N), w(N), x(N);
    for(int i = 0; i < N; ++i) cin >> h[i] >> w[i] >> x[i];
    
    vector<vector<string>> res(H, vector<string>(W));
    for(int i = 0; i < H; ++i) {
        for(int k = 0; k < W; ++k) {
            res[i][k] = ".";
        }
    }
    
    vector<int> tmp(W);
    for(int m = 0; m < N; ++m) { // ブロックを1つ目から順番に評価する
        for(int h_i = 0; h_i < h[m]; ++h_i) {
            for(int w_i = 0; w_i < w[m]; ++w_i) {
                int max_n = 0;
                for(int mi = x[m]; mi < w[m] + x[m]; ++mi) {
                    if(tmp[mi] > max_n) {
                        max_n = tmp[mi];
                    }
                }
                res[ h_i + max_n ][ x[m] + w_i ] = "#";
            }
        }

        for(int k = 0; k < W; ++k) {
            for(int i = H - 1; i >= 0; --i) {
                if(res[i][k] == "#") {
                    tmp[k] = i + 1;
                    break;
                }
            }
        }
    }
    
    // 標準出力
    for(int i = H - 1; i >= 0; --i) {
        for(int k = 0; k < W; ++k) {
            cout << res[i][k];
        }
        cout << endl;
    }
    
    return 0;
}