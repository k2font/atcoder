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
  string N; cin >> N; int K; cin >> K;
  auto dp = make_vec<ll>(N.size() + 10, 2, K + 10);
  REP(i, N.size() + 10) {
    REP(j, 2) {
      REP(k, K + 10) {
        dp[i][j][k] = 0;
      }
    }
  }
  dp[0][0][0] = 1;

  REP(i, N.size()) {
    int D = N[i] - '0';
    REP(j, 2) {
      REP(k, K + 1) {
        for(int d = 0; d <= (j ? 9 : D); ++d) {
          if(d == 0) dp[i + 1][j || (d < D)][k] += dp[i][j][k];
          else dp[i + 1][j || (d < D)][k + 1] += dp[i][j][k];
        }
      }
    }
  }
  cout << dp[N.size()][0][K] + dp[N.size()][1][K] << endl;
}