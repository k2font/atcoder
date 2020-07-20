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
  int H, W; cin >> H >> W;
  vector<string> S(H); REP(i, H) cin >> S[i];
  const int dx[4] = {1, 0, -1, 0};
  const int dy[4] = {0, -1, 0, 1};
  int ans = 0;
  REP(i, H) {
    REP(k, W) {
      vector<vector<bool>> flag(H, vector<bool>(W, false));
      if(S[i][k] == '#') continue;
      flag[i][k] = true;
      queue<pair<pair<int, int>, int>> Q; Q.push(make_pair(make_pair(i, k), 0));
      while (!Q.empty()) {
        auto p = Q.front(); Q.pop();
        int x = p.first.first; int y = p.first.second;
        // flag[x][y] = true;
        for(int i = 0; i < 4; ++i) {
          if(x + dx[i] < 0 || x + dx[i] >= H) continue;
          if(y + dy[i] < 0 || y + dy[i] >= W) continue;
          if(flag[x + dx[i]][y + dy[i]] == true) continue;
          if(S[x + dx[i]][y + dy[i]] == '#') continue;
          flag[x + dx[i]][y + dy[i]] = true;
          Q.push(make_pair(make_pair(x + dx[i], y + dy[i]), p.second + 1));
          if(ans < p.second + 1) ans = p.second + 1;
        }
      }
    }
  }
  cout << ans << endl;
}