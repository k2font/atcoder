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
  int N; cin >> N;
  int M; cin >> M;
  vector<ll> a(M), b(M);
  vector<int> c(M, 0); // bitで表す
  REP(i, M) {
    cin >> a[i] >> b[i];
    REP(k, b[i]) {
      ll t; cin >> t; --t;
      c[i] += (1 << t);
    }
  }

  // bitDPでした
  const long long INF = 1LL<<60;
  int lp = 5000; // 定数を入れるようにしよう
  vector<vector<ll>> dp(M + 10, vector<ll>(lp, INF));
  dp[0][0] = 0;

  for(int i = 0; i < M; ++i) {
    for(int k = 0; k < (1 << N); ++k) {
      chmin(dp[i + 1][k], dp[i][k]);
      int nk = k | c[i];
      chmin(dp[i + 1][k | c[i]], dp[i][k] + a[i]);
    }
  }

  cout << (dp[M][(1<<N)-1] < INF ? dp[M][(1<<N)-1] : -1) << endl; 
}
