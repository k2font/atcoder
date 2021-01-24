#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
struct edge {
  ll to, cost;
};

const int INF = 1001001001;

int main() {
  int H, W; cin >> H >> W;
  vector<string> a(H);
  REP(i, H) cin >> a[i];
  // ワープ使う時、Sから最も近いワープマスからワープするのが最善。
  // BFS中に最初にたどり着いたマスから全部のワープマスへワープするようにすると計算量が落ちる
  vector<vector<int>> dist(H, vector<int>(W, INF));
  queue<P> q;
  REP(i, H) {
    REP(j, W) {
      // Sを探す
      if(a[i][j] == 'S') {
        q.emplace(i, j); //push_backでpairを使ってpushする代わりに、pair型の値をpushしてくれる関数
        dist[i][j] = 0;
      }
    }
  }

  vector<vector<P>> warps(256);
  REP(i, H) {
    REP(j, W) {
      warps[a[i][j]].emplace_back(i, j);
    }
  }

  while(!q.empty()) {
    // 今から見る座標を取得する
    int i = q.front().first; int j = q.front().second;
    // queueから先頭を取り除く
    q.pop();
    // ゴールなら今いる位置の数字を出力する
    if(a[i][j] == 'G') {
      cout << dist[i][j] << endl;
      return 0;
    }
    //上下4方向を探索する
    REP(v, 4) {
      int ni = i + dx[v]; int nj = j + dy[v];
      if(ni < 0 || ni >= H || nj < 0 || nj >= W) continue; // 範囲外ならループをスキップ
      if(a[ni][nj] == '#') continue; // 壁ならループをスキップ
      if(dist[ni][nj] != INF) continue;
      dist[ni][nj] = dist[i][j] + 1;
      q.emplace(ni, nj);
    }

    if(islower(a[i][j])) { // 英字小文字なら...
      for(P p: warps[a[i][j]]) { // warpできる文字の位置を全探索する
        int ni = p.first; int nj = p.second;
        if(dist[ni][nj] != INF) continue;
        dist[ni][nj] = dist[i][j] + 1;
        q.emplace(ni, nj);
      }
      warps[a[i][j]].clear(); // 一度使ったワープ先は空にする
    }
  }
  cout << -1 << endl;
}