#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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
  int N; cin >> N;
  ll W; cin >> W;
  vector<ll> w(N), v(N); REP(i, N) cin >> w[i] >> v[i];
  vector<vector<ll>> dp(N + 1, vector<ll>(4));
  ll w1 = w[0];
  REP(i, N) {
    for(int j = w[i]; j <= w1 + 3; ++j) {
      dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
    }
  }
  REP(i, N + 1) {
    REP(k, W) {
      cout << dp[i][k] << " ";
    }
    cout << endl;
  }
}