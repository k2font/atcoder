// https://qiita.com/drken/items/a803d4fc4a727e02f7ba#4-1-s-%E3%81%8B%E3%82%89-t-%E3%81%B8%E8%BE%BF%E3%82%8A%E7%9D%80%E3%81%91%E3%82%8B%E3%81%8B

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

vector<bool> seen;
void dfs(vector<vector<int>> &G, int v) {
    seen[v] = true; // vを訪問済みにする

    // vから行ける拡張点 next_v について
    for(auto next_v : G[v]) {
        if(seen[next_v]) continue; // 訪問済みなら離脱
        dfs(G, next_v);// 再帰的に探索する
    }
}

int main(){
    int N, M, s, t; cin >> N >> M >> s >> t;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b); // 有向グラフだから一つで良い。
    }

    seen.assign(N ,false);
    dfs(G, s);

    if(seen[t]) cout << "Yes" << endl;
    else cout << "No" << endl;
}