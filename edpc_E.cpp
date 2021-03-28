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
  ll N, W; cin >> N >> W; const ll INF = 1000000000000;
  vector<ll> w(N), v(N); REP(i, N) cin >> w[i] >> v[i];
  vector<vector<ll>> dp(N + 100, vector<ll>(101000, INF)); // 品物i番目を取ってその時の価値の合計がkのときの、重さの最小値
  dp[0][0] = 0;
  for(int i = 0; i < N; ++i) {
    for(int k = 0; k <= 100001; ++k) { // 100 * 1000 = 10^5くらい
      // 品物を取るとき
      if(k - v[i] >= 0) chmin(dp[i + 1][k], dp[i][k - v[i]] + w[i]);
      chmin(dp[i + 1][k], dp[i][k]); // 品物を取らないとき
    }
  }

  // dp[N][k]をkが大きい順に見ていって、初めてW以下であればそれが答え
  for(int k = 100001; k >= 0; --k) {
    if(dp[N][k] <= W) {
      cout << k << endl;
      break;
    }
  }
}