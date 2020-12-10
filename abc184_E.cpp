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

int main() {
  int H, W; cin >> H >> W;
  vector<string> a(H);
  REP(i, H) cin >> a[i];
  int ans = pow(10, 9) + 7;
  int sx, sy, gx, gy;
  map<char, int> s, g;
  vector<vector<int>> res_s(H, vector<int>(W, -1)); // そのマスにたどり着くまでの最小回数を記録しておく
  vector<vector<int>> res_g(H, vector<int>(W, -1)); // そのマスにたどり着くまでの最小回数を記録しておく

  // sx, sy, gx, gyを特定する
  REP(i, H) {
    REP(k, W) {
      if(a[i][k] == 'S') {
        sx = i; sy = k;
      }
      if(a[i][k] == 'G') {
        gx = i; gy = k;
      }
    }
  }
  
  res_s[sx][sy] = 0;
  queue<pair<pair<int, int>, int>> q; q.push(make_pair(make_pair(sx, sy), 0));
  while(!q.empty()) { // res_sを埋める
    auto p = q.front(); q.pop();
    for(int i = 0; i < 4; ++i) {
      int x = p.first.first + dx[i]; int y = p.first.second + dy[i];
      if(x < 0 || x >= H) continue;
      if(y < 0 || y >= W) continue;
      if(res_s[x][y] != -1) continue;
      if(a[x][y] == '#') continue;
      res_s[x][y] = p.second + 1;
      q.push(make_pair(make_pair(x, y), res_s[x][y]));
    }
  }

  res_g[gx][gy] = 0; q.push(make_pair(make_pair(gx, gy), 0));
  while(!q.empty()) { // res_gを埋める
    auto p = q.front(); q.pop();
    for(int i = 0; i < 4; ++i) {
      int x = p.first.first + dx[i]; int y = p.first.second + dy[i];
      if(x < 0 || x >= H) continue;
      if(y < 0 || y >= W) continue;
      if(res_g[x][y] != -1) continue;
      if(a[x][y] == '#') continue;
      res_g[x][y] = p.second + 1;
      q.push(make_pair(make_pair(x, y), res_g[x][y]));
    }
  }

  REP(i, H) {
    REP(k, W) {
      if(a[i][k] == '.' || a[i][k] == '#' || a[i][k] == 'S' || a[i][k] == 'G') continue;
      s[a[i][k]] = max(s[a[i][k]], res_s[i][k]);
    }
  }

  REP(i, H) {
    REP(k, W) {
      if(a[i][k] == '.' || a[i][k] == '#' || a[i][k] == 'S' || a[i][k] == 'G') continue;
      s[a[i][k]] = min(s[a[i][k]], res_s[i][k]);
    }
  }

  REP(i, H) {
    REP(k, W) {
      if(a[i][k] == '.' || a[i][k] == '#' || a[i][k] == 'S' || a[i][k] == 'G') continue;
      g[a[i][k]] = max(s[a[i][k]], res_g[i][k]);
    }
  }

  REP(i, H) {
    REP(k, W) {
      if(a[i][k] == '.' || a[i][k] == '#' || a[i][k] == 'S' || a[i][k] == 'G') continue;
      g[a[i][k]] = min(s[a[i][k]], res_g[i][k]);
    }
  }

  for(auto x : s) {
    int p = x.second + g[x.first];
    ans = min(ans, p);
  }
  
  if(res_s[gx][gy] == -1) cout << -1 << endl;
  else cout << min(ans, res_s[gx][gy]) << endl;
}