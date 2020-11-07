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
  int ch, cw, dh, dw; cin >> ch >> cw >> dh >> dw;
  ch--; cw--; dh--; dw--;
  vector<string> S(H);
  vector<vector<int>> res(H, vector<int>(W, 0));
  REP(i, H) cin >> S[i];
  deque<P> q; q.push_front(P(ch, cw));
  while(!q.empty()) {
    auto a = q.front(); q.pop();
    for(int i = 0; i < 4; ++i) {
      int x = a.first + dx[i]; int y = a.second + dy[i];
      if(!(0 <= x && x < H && 0 <= y && t < W)) continue;
      if(res[x][y] != -1) continue;
      q.push_front(P(x, y));
      res[x][y] = res[a.first][a.second] + 1;
    }
  }
  cout << res[dh][dw] << endl;
}