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
  vector<double> p(N); REP(i, N) cin >> p[i];
  vector<vector<double>> dp(N + 100, vector<double>(N + 100, 0));
  dp[0][0] = 1;
  REP(i, N) {
    REP(k, N + 1) {
      dp[i + 1][k + 1] += dp[i][k] * p[i];
      dp[i + 1][k] += dp[i][k] * (1 - p[i]);
    }
  }
  double ans = 0.0;
  REP(i, N + 1) {
    // 表の枚数が裏より多い場合だけansに足し込む
    if(i > N - i) ans += dp[N][i];
  }
  cout << fixed << setprecision(10) << ans << endl;
}