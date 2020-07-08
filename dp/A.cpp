// https://qiita.com/drken/items/dc53c683d6de8aeacf5a#a-%E5%95%8F%E9%A1%8C---frog-1
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

int main() {
  int N; cin >> N;
  vector<int> h(N); REP(i, N) cin >> h[i];

  vector<int> dp(100010);
  ll INF = pow(10, 9) + 7;
  REP(i, 100010) {
    dp[i] = INF;
  }

  dp[0] = 0;
  dp[1] = dp[0] + abs(h[1] - h[0]);

  for(int i = 2; i < N; ++i) {
    chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
    chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
  }
  
  cout << dp[N - 1] << endl;
}