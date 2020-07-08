#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// 四方向への移動ベクトル
const int dx[4] = {1, 0};
const int dy[4] = {0, 1};

int H, W;
vector<string> field;

// 探索
int cnt[100][100];
int res = 10000007;

int seen[510][510]; // seen[h][w] := マス (h, w) が検知済みかどうか

void dfs(int h, int w, int _cnt) {
    seen[h][w]++;
    // 四方向を探索
    for (int dir = 0; dir < 2; ++dir) {
        int nh = h + dx[dir];
        int nw = w + dy[dir];

        // 場外アウトしたり、移動先が壁の場合はスルー
        if ( nh >= H || nw >= W ) continue;

        // 移動先が探索済みの場合
        if (seen[nh][nw] > 80) continue;

        if (field[nh][nw] == '#') {
            if(cnt[nh][nw] >= _cnt + 1) {
                cnt[nh][nw] = _cnt + 1;
            } else {
                cnt[nh][nw] = _cnt;
            }
        } else {
            cnt[nh][nw] = _cnt;
        }

        if(nh + 1 == H && nw + 1 == W) {
            if(res > cnt[nh][nw]) {
                res = cnt[nh][nw];
            }
        }

        // cout << nh << " " << nw << " " << cnt[nh][nw] << " " << field[nh][nw] << endl;

        // 再帰的に探索
        dfs(nh, nw, cnt[nh][nw]);
    }
}

int main(){
    cin >> H >> W;
    field.resize(H); REP(i, H) cin >> field[i];

    memset(cnt, 100000007, sizeof(cnt));

    // 探索開始
    if(field[0][0] == '#') {
        dfs(0, 0, 1); // スタート位置
    } else {
        dfs(0, 0, 0); // スタート位置
    }

    cout << res << endl;
}