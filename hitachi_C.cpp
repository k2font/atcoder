#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> a(N - 1), b(N - 1); for(int i = 0; i < N - 1; ++i) cin >> a[i] >> b[i];

    constexpr int INF = 1e8;

    vector<vector<long long>> d(N, vector<long long>(N, INF));
    for (int i = 0; i < N - 1; i++) {
        d[i][i] = 0;
        d[a[i] - 1][b[i] - 1] = 1;
        d[b[i] - 1][a[i] - 1] = 1;
        
    }

    // ワーシャルフロイドで全頂点間の最短経路を計算する
    for (int k = 0; k < N; k++){       // 経由する頂点
        for (int i = 0; i < N; i++) {    // 始点
            for (int j = 0; j < N; j++) {  // 終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    vector<pair<int, int>> p;
    vector<int> res(N); for(int i = 0; i < N; ++i) res[i] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if(d[i][j] == 3) {
                p.push_back(make_pair(i + 1, j + 1));
            }
        }
    }

    for(int i = 0; i < p.size(); ++i) {
        res[p[i].first - 1] = 2;
        res[p[i].second - 1] = 3;
    }

    for(int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }

    cout << endl;
}