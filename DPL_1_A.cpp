#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
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
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
  int n, m; cin >> n >> m;
  vector<int> c(m); REP(i, m) cin >> c[i];
  int dp[30][50010];
  REP(i, 30) {
    REP(k, 50010) {
      dp[i][k] = 10000010;
    }
  }
  for(int i = 0; i < m; ++i) {
    dp[1][c[i]] = 1;
  }
  for(int i = 0; i < m; ++i) {
    for(int k = 0; k <= n; ++k) {
      if(k - c[i] >= 0) {
        chmin(dp[i + 1][k], dp[i][k - c[i]] + 1);
        chmin(dp[i + 1][k], dp[i + 1][k - c[i]] + 1);
      }
      chmin(dp[i + 1][k], dp[i][k]);
    }
  }
  cout << dp[m][n] << endl;
}