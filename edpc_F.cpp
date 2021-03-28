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
  // LCS!!!
  string s, t; cin >> s >> t;
  vector<vector<ll>> dp(s.size() + 1, vector<ll>(t.size() + 1, 0));

  REP(i, s.size()) {
    REP(k, t.size()) {
      // もしいま見ている位置が一致すれば...
      if(s[i] == t[k]) chmax(dp[i + 1][k + 1], dp[i][k] + 1); // どちらの文字も採用する
      // そうでない場合、sとtのどちらかの文字を捨てる
      chmax(dp[i + 1][k + 1], dp[i][k + 1]);
      chmax(dp[i + 1][k + 1], dp[i + 1][k]);
    }
  }

  // 復元する
  string ans = "";
  ll i = s.size(); ll k = t.size();
  while(i > 0 && k > 0) {
    if(dp[i - 1][k] == dp[i][k]) --i;
    else if(dp[i][k - 1] == dp[i][k]) --k;
    else {
      ans = ans + s[i - 1];
      --i; --k;
    }
  }
  reverse(all(ans));
  cout << ans << endl;
}