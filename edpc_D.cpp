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
  ll N, W; cin >> N >> W;
  vector<ll> w(N), v(N); REP(i, N) cin >> w[i] >> v[i];
  vector<vector<ll>> dp(N + 100, vector<ll>(W + 100, 0));
  REP(i, N) {
    for(int k = 0; k <= W; ++k) {
      if(k - w[i] >= 0) chmax(dp[i + 1][k], dp[i][k - w[i]] + v[i]);
      chmax(dp[i + 1][k], dp[i][k]);
    }
  }

  ll ans = 0;
  REP(i, N + 1) {
    REP(k, W + 1) {
      chmax(ans, dp[i][k]);
    }
  }
  cout << ans << endl;
}