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
  ll N, M; cin >> N >> M;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> B(M); REP(i, M) cin >> B[i];

  // LCSと似たようなDPをする。
  vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 1000000000000009));
  dp[0][0] = 0;
  REP(i, N + 1) {
    REP(k, M + 1) {
      if(k > 0) chmin(dp[i][k], dp[i][k - 1] + 1);
      if(i > 0) chmin(dp[i][k], dp[i - 1][k] + 1);
      if(i > 0 && k > 0) {
        if(A[i - 1] == B[k - 1]) chmin(dp[i][k], dp[i - 1][k - 1]);
        else chmin(dp[i][k], dp[i - 1][k - 1] + 1);
      }
    }
  }
  cout << dp[N][M] << endl;
}
