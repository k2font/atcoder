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
  ll N; cin >> N;
  vector<ll> a(N), b(N), c(N); REP(i, N) cin >> a[i] >> b[i] >> c[i];
  vector<vector<ll>> dp(N + 100, vector<ll>(3, 0));
  dp[0][0] = a[0]; dp[0][1] = b[0]; dp[0][2] = c[0];
  REP(i, N) {
    if(i - 1 < 0) continue;
    chmax(dp[i][0], dp[i - 1][1] + a[i]);
    chmax(dp[i][2], dp[i - 1][1] + c[i]);
    chmax(dp[i][1], dp[i - 1][0] + b[i]);
    chmax(dp[i][2], dp[i - 1][0] + c[i]);
    chmax(dp[i][0], dp[i - 1][2] + a[i]);
    chmax(dp[i][1], dp[i - 1][2] + b[i]);
  }
  cout << max(dp[N - 1][0], max(dp[N - 1][1], dp[N - 1][2])) << endl;
}