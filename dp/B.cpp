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
  int N, K; cin >> N >> K;
  vector<int> h(N); REP(i, N) cin >> h[i];

  vector<int> dp(100010);
  ll INF = pow(10, 9) + 7;
  REP(i, 100010) {
    dp[i] = INF;
  }

  dp[0] = 0;

  for(int i = 1; i < N; ++i) {
    for(int k = i - K; k < i; ++k) {
      if(k < 0) continue;
      chmin(dp[i], dp[k] + abs(h[i] - h[k]));
    }
  }
  cout << dp[N - 1] << endl;
}