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
  ll N; cin >> N;
  string S, X; cin >> S >> X;
  vector<vector<ll>> dp(N + 100, vector<ll>(7)); // iターン目のとき、余りがkの場合に高橋くんが勝つなら1。バッファをもたせる

  dp[N][0] = 1; // Nターン目にあまりが0なら高橋くんが勝つ

  for(int i = N - 1; i >= 0; --i) {
    for(int k = 0; k < 7; ++k) {
      ll zero = dp[i + 1][10 * k % 7];
      ll s = dp[i + 1][(10 * k + char_to_int(S[i])) % 7];
      if(X[i] == 'T' && zero + s > 0) dp[i][k] = 1;
      else if(X[i] == 'A' && zero * s == 1) dp[i][k] = 1;
    }
  }

  if(dp[0][0]) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
}