// https://qiita.com/drken/items/a803d4fc4a727e02f7ba#%E3%82%B0%E3%83%AA%E3%83%83%E3%83%89%E3%82%B0%E3%83%A9%E3%83%95%E3%81%AE%E5%A0%B4%E5%90%88

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bool seen[510][510]; // マスh,wが検知済みかどうか
int H, W;

int main(){
    cin >> H >> W;
    vector<vector<char>> c(H, vector<char>(W));
    REP(i, H) {
        REP(k, W) {
            cin >> c[i][k];
        }
    }

    // sとgのマスを特定する
    // shなどは初期値の指定、およびゴールの指定に使われる
    int sh, sw, gh, gw;
    REP(i, H) {
        REP(k, W) {
            if(c[i][k] == 's') sh = i, sw = k;
            if(c[i][k] == 'g') gh = i, gw = k;
        }
    }

    memset(seen, 0, sizeof(seen));
    seen[sh][sw] = true;

    // 4方向を探索する
    for(int i = 0; i < 4; ++i) {
        int nh = sh + dx[i];
        int nw = sw + dy[i];

        if(nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if(c[nh][nw] == '#') continue;
        if(seen[nh][nw]) continue;

        dfs(nh, nw);
    }

    // 結果
    if(seen[gh][gw]) cout << "Yes" << endl;
    else cout << "No" << endl;
}