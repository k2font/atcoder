#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

vector<bool> seen;
vector<int> first_order; // 行きがけ順
vector<int> last_order; // 帰りがけ順
void dfs(const vector<vector<int>> &G, int v, int& first_ptr, int& last_ptr) {
    first_order[v] = first_ptr++;
    
    seen[v] = true;

    for(auto next_v: G[v]) {
        if(seen[next_v]) continue; // next_vがtrue、つまり探索済みであればスルー
        dfs(G, next_v, first_ptr, last_ptr);
    }

    last_order[v] = last_ptr++;
}

int main(){
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    vector<vector<int>> G(N);
    // グラフの入力を受け取り
    for(int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, false); // 全頂点を未訪問として初期化する
    first_order.resize(N);
    last_order.resize(N);
    int first_ptr = 0;
    int last_ptr = 0;
    dfs(G, 0, first_ptr, last_ptr);

    for(int v = 0; v < N; ++v) {
        cout << v << ": " << first_order[v] << ", " << last_order[v] << endl;
    }
}