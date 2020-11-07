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

const ll INF = 1e9;
int main() {
  int N; cin >> N;
  int K; cin >> K;
  vector<int> h(N); REP(i, N) cin >> h[i];
  vector<ll> dp(N, INF); dp[0] = 0;
  REP(i, N) {
    for(int k = 1; k <= K; ++k) {
      if(i - k < 0) continue;
      chmin(dp[i], dp[i - k] + abs(h[i] - h[i - k]));
    }
  }
  cout << dp[N - 1] << endl;
}