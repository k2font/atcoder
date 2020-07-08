#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int, int>;
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
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}
struct edge {
  ll to, cost;
};

int main() {
  int H, W; cin >> H >> W;
  vector<string> s(H); REP(i, H) cin >> s[i];
  vector<vector<int>> f(H, vector<int>(W, -1));
  int all_num = 0;
  REP(i, H) {
    REP(k, W) {
      if(s[i][k] == '.') all_num++;
    }
  }
  queue<P> q; q.push(make_pair(0, 0));
  int cnt = 0; f[0][0] = 1;
  while(!q.empty()) {
    auto p = q.front(); q.pop();
    int x = p.first; int y = p.second;
    cnt++;
    for(int i = 0; i < 4; ++i) {
      if(x + dx[i] < 0 || x + dx[i] >= H) continue;
      if(y + dy[i] < 0 || y + dy[i] >= W) continue;
      if(s[x + dx[i]][y + dy[i]] == '#') continue;
      if(f[x + dx[i]][y + dy[i]] != -1) continue;
      f[x + dx[i]][y + dy[i]] = f[x][y] + 1;
      q.push(make_pair(x + dx[i], y + dy[i]));
    }
  }
  if(f[H - 1][W - 1] == -1) cout << -1 << endl;
  else cout << all_num - f[H - 1][W - 1] << endl;
}