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
  int N, M; cin >> N >> M;
  vector<int> x(M), y(M); REP(i, M) cin >> x[i] >> y[i];
  vector<vector<bool>> bad(16, vector<bool>(16));
  REP(i, M) {
    x[i]--; y[i]--;
    bad[y[i]][x[i]] = true;
  }
  // bitDP
  vector<ll> dp(1 << 16, 0);
  dp[0] = 1; // 0個の頂点の場合は1通りの並べ方がある
  for(int i = 0; i < (1 << N); ++i) {
    REP(k, N) {
      if(!(1 & (i >> k))) {
        bool ok = true;
        REP(m, N) {
          if(1 & (i >> m)) {
            if(bad[m][k]) ok = false;
          }
        }
        if(ok) dp[i + (1 << k)] += dp[i];
      }
    }
  }
  cout << dp[(1 << N) - 1] << endl;
}
