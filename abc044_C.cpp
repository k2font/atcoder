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

// 多次元 vector 生成を行うテンプレート
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
  int N, A; cin >> N >> A;
  vector<ll> x(N); REP(i, N) cin >> x[i];
  auto dp = make_vec<ll>(N + 1, N + 1, 2502);
  REP(i, N) {
    REP(k, N) {
      REP(m, 2501) {
        dp[i][k][m] = 0;
      }
    }
  }

  dp[0][0][0] = 1;

  REP(i, N) {
    REP(k, N) { 
      REP(m, 2501) {
        if(dp[i][k][m] == 0) continue;
        dp[i + 1][k][m] += dp[i][k][m];
        dp[i + 1][k + 1][m + x[i]] += dp[i][k][m];
      }
    }
  }

  ll ans = 0;
  REP(i, N + 1) {
    if(i == 0) continue;
    ans += dp[N][i][i * A];
  }
  cout << ans << endl;
}