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
  string N; cin >> N;
  vector<vector<ll>> dp(N.size() + 10, vector<ll>(2, 0));
  dp[0][1] = 1;
  REP(i, N.size()) {
    int D = N[i] - '0';
    dp[i + 1][0] = min(dp[i][0] + D, dp[i][1] + (10 - D));
    dp[i + 1][1] = min(dp[i][0] + D + 1, dp[i][1] + (10 - D - 1));
  }
  cout << dp[N.size()][0] << endl;
}