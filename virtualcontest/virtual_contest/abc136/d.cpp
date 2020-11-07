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

const int MOD = pow(10, 9) + 7;
const int INF = pow(10, 9);

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int H, W;
vector<vector<ll>> a;
vector<vector<ll>> dp;

ll dfs(int y, int x) {
  if(dp[y][x] != -1) return dp[y][x];
  ll ret = 1;
  REP(i, 4) {
    int ny = y + dy[i], nx = x + dx[i];
    if(!(0 <= ny && ny < H && 0 <= nx && nx < W)) {
      continue;
    }
    if(a[y][x] < a[ny][nx]) {
      ret += dfs(ny, nx);
      ret %= MOD;
    }
  }
  return dp[y][x] = ret;
}

int main() {
  cin >> H >> W;
  a.resize(H, vector<ll>(W));
  dp.resize(1010, vector<ll>(1010, -1));
  REP(i, H) {
    REP(k, W) {
      cin >> a[i][k];
    }
  }
  ll ans = 0;
  REP(i, H) {
    REP(k, W) {
      ans += dfs(i, k);
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
