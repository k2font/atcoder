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
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

int main() {
  int N; cin >> N;
  vector<ll> T(N); REP(i, N) cin >> T[i];
  ll res = accumulate(all(T), 0LL);
  vector<vector<bool>> dp(N + 10, vector<bool>(res + 10, false));
  dp[0][0] = true;
  for(int i = 0; i < N; ++i) {
    for(int k = 0; k <= res; ++k) {
      dp[i + 1][k] = (dp[i + 1][k] | dp[i][k]);
      if(k - T[i] >= 0) dp[i + 1][k] = (dp[i + 1][k] | dp[i][k - T[i]]);
    }
  }
  ll ans = 1e18;
  REP(k, res) {
    if(dp[N][k]) ans = min(ans, max((ll)k, res - k));
  }
  cout << ans << endl;
}