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
  string s1, s2; cin >> s1 >> s2;
  vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));

  REP(i, s1.size()) {
    REP(k, s2.size()) {
      if(s1[i] == s2[k]) chmax(dp[i + 1][k + 1], dp[i][k] + 1);
      chmax(dp[i + 1][k + 1], dp[i][k + 1]);
      chmax(dp[i + 1][k + 1], dp[i + 1][k]);
    }
  }

  // 復元する
  string ans = "";
  int i = s1.size(); int k = s2.size();
  while(i > 0 && k > 0) {
    if(dp[i - 1][k] == dp[i][k]) {
      --i;
    } else if(dp[i][k - 1] == dp[i][k]) {
      --k;
    } else {
      ans = ans + s1[i - 1];
      --i; --k;
    }
  }
  reverse(all(ans));
  cout << ans << endl;
}