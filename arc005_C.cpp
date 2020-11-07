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
char upper_to_lower(char c) {
  return tolower(c);
}
char lower_to_upper(char c) {
  return toupper(c);
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

int main() {
  int H, W; cin >> H >> W;
  vector<string> c(H); REP(i, H) cin >> c[i];
  // スタートとゴールの位置の特定
  int sx, sy, gx, gy;
  REP(i, H) {
    REP(k, W) {
      if(c[i][k] == 's') {
        sx = i; sy = k;
      }
      if(c[i][k] == 'g') {
        gx = i; gy = k;
      }
    }
  }
  vector<vector<int>> ans(H, vector<int>(W, 10000));
  // 探索
  ans[sx][sy] = 0;
  deque<P> q; q.push_back(P(sx, sy));
  while(!q.empty()) {
    auto p = q.front(); q.pop_front();
    for(int i = 0; i < 4; ++i) {
      int x = p.first + dx[i]; int y = p.second + dy[i];
      if(x < 0 || x >= H) continue;
      if(y < 0 || y >= W) continue;
      if(c[x][y] == '#' && (ans[p.first][p.second] + 1 < ans[x][y])) {
        q.push_back(P(x, y));
        ans[x][y] = ans[p.first][p.second] + 1;
      } else if((c[x][y] == '.' || c[x][y] == 'g') && (ans[p.first][p.second] < ans[x][y])) {
        q.push_front(P(x, y));
        ans[x][y] = ans[p.first][p.second];
      }
    }
  }
  // REP(i, H) {s
  //   REP(k, W) {
  //     cout << ans[i][k] << " ";
  //   }
  //   cout << endl;
  // }
  if(ans[gx][gy] <= 2) cout << "YES" << endl;
  else cout << "NO" << endl;
}