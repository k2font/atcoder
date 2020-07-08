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
  int q; cin >> q;
  vector<string> X(q), Y(q); REP(i, q) cin >> X[i] >> Y[i];
  vector<vector<int>> dp(1010, vector<int>(1010));
  for(int i = 0; i < q; ++i) {
    REP(a, 1010) {
      REP(b, 1010) {
        dp[a][b] = 0;
      }
    }
    for(int k = 0; k < X[i].size(); ++k) {
      for(int m = 0; m < Y[i].size(); ++m) {
        if(X[i][k] == Y[i][m]) dp[k + 1][m + 1] = max(dp[k + 1][m + 1], dp[k][m] + 1);
        dp[k + 1][m + 1] = max(dp[k + 1][m + 1], dp[k + 1][m]);
        dp[k + 1][m + 1] = max(dp[k + 1][m + 1], dp[k][m + 1]);
      }
    }
    cout << dp[X[i].size()][Y[i].size()] << endl;
  }
}