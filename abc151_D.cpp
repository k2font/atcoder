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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int main() {
  int H, W; cin >> H >> W;
  vector<string> S(H); REP(i, H) cin >> S[i];
  ll INF = pow(10, 9);
  vector<vector<int>> dp(500, vector<int>(500, INF));
  for(int i = 0; i < 500; ++i) {
    dp[i][i] = 0;
  }
  auto id = [&](int x, int y) {return x * W + y;};

  // 全マスを4方向に進めるかどうか判定する
  for(int i = 0; i < H; ++i) {
    for(int k = 0; k < W; ++k) {
      if(S[i][k] == '#') continue;
      for(int m = 0; m < 4; ++m) {
        if(i + dx[m] < 0 || i + dx[m] >= H || k + dy[m] < 0 || k + dy[m] >= W) {
          continue;
        }
        if(S[i + dx[m]][k + dy[m]] == '#') {
          continue;
        }
        dp[id(i, k)][id(i + dx[m], k + dy[m])] = 1;
        dp[id(i + dx[m], k + dy[m])][id(i, k)] = 1;
      }
    }
  }

  for (int k = 0; k < 500; k++){       // 経由する頂点
    for (int i = 0; i < 500; i++) {    // 始点
      for (int j = 0; j < 500; j++) {  // 終点
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  int ans = 0;
  REP(i, 500) {
    REP(k, 500) {
      if(dp[i][k] != 1000000000 && ans < dp[i][k]) ans = dp[i][k];
    }
  }
  cout << ans << endl;
}