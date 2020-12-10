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
  string N; cin >> N;
  int l = N.size();
  auto dp = make_vec<int>(20, 2, 20);

  dp[0][0][0] = 1; // 初期条件。その他はすべて0で初期化する。

  for(int i = 0; i < l; ++i) {
    for(int x = 0; x <= 9; ++x) {
      // i桁目まででNより小さいなら、i + 1桁目は何でも良い(未満フラグを建てる)
      dp[i + 1][1][x] += dp[i][1][x] * 9; // i + 1桁目が1以外
      dp[i + 1][1][x + 1] += dp[i][1][x]; // i + 1桁目が1

      // i桁目までNと同じで、i + 1桁目はNより小さい数の時
      if(char_to_int(N[i]) > 1) {
        dp[i + 1][1][x] += dp[i][0][x] * (char_to_int(N[i]) - 1); // i + 1桁目が0〜ni - 1のとき
        dp[i + 1][1][x + 1] += dp[i][0][x]; // i + 1桁目が1のとき
      } else if(char_to_int(N[i]) == 1) {
        dp[i + 1][1][x] += dp[i][0][x]; // i + 1桁目が0
      }

      // i桁目までNと同じで、i + 1桁目もNと同じ数の時
      if(char_to_int(N[i]) == 1) {
        dp[i + 1][0][x + 1] = dp[i][0][x]; // i + 1桁目が1
      } else {
        dp[i + 1][0][x] = dp[i][0][x]; // i + 1桁目が1以外
      }
    }
  }

  ll ans = 0;
  REP(i, 10) {
    ans += (dp[l][0][i] + dp[l][1][i]) * i;
  }
  cout << ans << endl;
}