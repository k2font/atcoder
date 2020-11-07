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

const ll INF = 1e18;
int main() {
  int N, W; cin >> N >> W;
  vector<ll> w(N), v(N); REP(i, N) cin >> w[i] >> v[i];
  auto dp = make_vec<ll>(N + 1, W + 1); // N番目の商品を選んだ時に重さがWとなる場合の価値の最大値
  REP(i, N + 1) {
    REP(k, W + 1) {
      dp[i][k] = 0;
    }
  }
  REP(i, N) {
    REP(k, W + 1) {
      if(k - w[i] >= 0) chmax(dp[i + 1][k], dp[i][k - w[i]] + v[i]);
      chmax(dp[i + 1][k], dp[i][k]); // 重さが足りなくて品物を足せないときの処理を忘れないように！
      // ナップザック問題はある品物それぞれを「選ぶ」「選ばない」2通りを考える必要がある。
    }
  }
  ll ans = 0;
  REP(i, N + 1) {
    REP(k, W + 1) {
      ans = max(ans, dp[i][k]);
      // cout << dp[i][k] << " ";
    }
    // cout << endl;
  }
  cout << ans << endl;
}