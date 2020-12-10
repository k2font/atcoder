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

/*
  N以下の数に3を含むものの個数は何個あるか？
  桁DPを使って解く
*/

int main() {
  string N; cin >> N;
  auto dp = make_vec<int>(N.size() + 1, 2, 2);

  // Nの各数字を格納する配列
  vector<int> n;
  for(auto x : N) {
    n.push_back(char_to_int(x));
  }

  int l = N.size();

  dp[0][0][0] = 1; // 初期条件。その他はすべて0で初期化する。
  for(int i = 0; i < l; ++i) {
    for(int smaller = 0; smaller < 2; ++smaller) {
      for(int j = 0; j < 2; ++j) {
        for(int x = 0; x <= (smaller ? 9 : n[i]); ++x) {
          // ここ参照
          // https://qiita.com/pinokions009/items/1e98252718eeeeb5c9ab#%E3%82%B3%E3%83%BC%E3%83%89
          dp[i + 1][smaller || x < n[i]][j || x == 3] += dp[i][smaller][j];
        }
      }
    }
  }
  cout << dp[l][0][1] + dp[l][1][1] << endl;
}