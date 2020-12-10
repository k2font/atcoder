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
  int H, W; cin >> H >> W;
  vector<string> s(H); REP(i, H) cin >> s[i];
  vector<vector<int>> dp(H, vector<int>(W, 10000));
  if(s[0][0] == '#') dp[0][0] = 1;
  else dp[0][0] = 0;
  REP(i, H) {
    REP(k, W) {
      if(i + 1 < H) {
        if(s[i + 1][k] == '#' && s[i][k] == '.') dp[i + 1][k] = min(dp[i + 1][k], dp[i][k] + 1);
        else                                     dp[i + 1][k] = min(dp[i + 1][k], dp[i][k]);
      }

      if(k + 1 < W) {
        if(s[i][k + 1] == '#' && s[i][k] == '.') dp[i][k + 1] = min(dp[i][k + 1], dp[i][k] + 1);
        else                                     dp[i][k + 1] = min(dp[i][k + 1], dp[i][k]);
      }
    }
  }
  if(s[H - 1][W - 1] == '#' && s[H - 1][W - 2] == '.') {
    dp[H - 1][W - 1] = min(dp[H - 1][W - 1], dp[H - 1][W - 2] + 1);
  } else {
    dp[H - 1][W - 1] = min(dp[H - 1][W - 1], dp[H - 1][W - 2]);
  }
  if(s[H - 1][W - 1] == '#' && s[H - 2][W - 1] == '.') {
    dp[H - 1][W - 1] = min(dp[H - 1][W - 1], dp[H - 2][W - 1] + 1);
  } else {
    dp[H - 1][W - 1] = min(dp[H - 1][W - 1], dp[H - 2][W - 1]);
  }
  cout << dp[H - 1][W - 1] << endl;
}