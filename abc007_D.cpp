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

auto dp = make_vec<ll>(32, 2, 2); // 決定した桁の数, N未満かどうか, 4か9を含むか
ll digitdp(ll n) {
  REP(i, 32) {
    REP(k, 2) {
      REP(j, 2) {
        dp[i][k][j] = 0;
      }
    }
  }
  dp[0][0][0] = 1;
  int L = to_string(n).size();
  string t = to_string(n);
  REP(i, L) {
    int D = t[i] - '0';
    REP(j, 2) {
      REP(k, 2) {
        for(int d = 0; d <= (j ? 9 : D); ++d) {
          dp[i + 1][j || (d < D)][k || d == 4 || d == 9] += dp[i][j][k];
        }
      }
    }
  }
  return dp[L][0][1] + dp[L][1][1];
}

int main() {
  ll A, B; cin >> A >> B;

  cout << digitdp(B) << endl;
}