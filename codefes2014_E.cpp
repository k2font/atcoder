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
  int N; cin >> N;
  vector<ll> R(N); REP(i, N) cin >> R[i];
  vector<vector<ll>> dp(N + 1, vector<ll>(2, 0));
  dp[0][0] = dp[0][1] = 1;
  REP(i, N) {
    if(i == 0) continue;
    for(int k = 0; k < i; ++k) {
      if(R[k] == R[i]) continue;
      if(R[k] < R[i]) chmax(dp[i][0], dp[k][1] + 1);
      if(R[k] > R[i]) chmax(dp[i][1], dp[k][0] + 1);
    }
  }
  ll ans = max(dp[N - 1][1], dp[N - 1][0]);
  if(ans > 2) cout << ans << endl;
  else cout << 0 << endl;
}
