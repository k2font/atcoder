#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
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

int main() {
  int R, C; cin >> R >> C;
  int sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx;
  vector<string> c(R); REP(i, R) cin >> c[i];
  const int dx[4] = {1, 0, -1, 0};
  const int dy[4] = {0, -1, 0, 1};
  queue<pair<int, int>> Q;
  Q.push(make_pair(sy, sx));
  vector<vector<int>> ans(R, vector<int>(C));
  REP(i, R) {
    REP(k, C) {
      ans[i][k] = -1;
    }
  }
  ans[sy - 1][sx - 1] = 0;
  while(!Q.empty()) {
    auto i = Q.front(); Q.pop();
    for(int k = 0; k < 4; ++k) {
      int x = i.first - 1; int y = i.second - 1;
      if(c[x + dx[k]][y + dy[k]] == '.') {
        if(ans[x + dx[k]][y + dy[k]] == -1) {
          Q.push(make_pair(i.first + dx[k], i.second + dy[k]));
          ans[x + dx[k]][y + dy[k]] = ans[x][y] + 1;
        }
      }
      if(i.first == gy && i.second == gx) {
        break;
      }
    }
  }
  cout << ans[gy - 1][gx - 1] << endl;
}
