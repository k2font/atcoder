#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
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
  vector<int> dp(100010, 10000000); dp[0] = 0;
  for(int i = 1; i <= N; ++i) {
    dp[i] = min(dp[i - 1] + 1, dp[i]);
    REP(k, 10) {
      if(i - pow(6, (k + 1)) >= 0) dp[i] = min(dp[i - pow(6, (k + 1))] + 1, dp[i]);
      if(i - pow(9, (k + 1)) >= 0) dp[i] = min(dp[i - pow(9, (k + 1))] + 1, dp[i]);
    }
  }
  cout << dp[N] << endl;
}