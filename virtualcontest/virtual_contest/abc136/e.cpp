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

int N;
vector<vector<ll>> tree;
const ll INF = 10000000000010; // 十分大きな値
vector<vector<ll>> dp;

ll rec(ll S, ll v) {
  if(S == 0) { // どのノードも通っていなければ
    if(v == 0) return 0; // スタート地点にいたら(つまり初期値は0)
    else return INF;
  }

  if((S & (1 << v)) == 0) return INF; // SにVが含まれていなければ

  ll &ret = dp[S][v];
  if(ret != 0) return ret; // すでにそのノードを見ていたら

  ret = INF;
  REP(u, N) {
    chmin(ret, rec(S ^ (1 << v), u) + tree[u][v]);
  }
  return ret;
}

int main() {
  cin >> N;
  vector<ll> X(N), Y(N), Z(N); REP(i, N) cin >> X[i] >> Y[i] >> Z[i];
  tree.resize(21, vector<ll>(21, INF));
  // コストを求める
  REP(i, N) {
    REP(k, N) {
      if(i == k) continue;
      tree[i][k] = abs(X[k] - X[i]) + abs(Y[k] - Y[i]) + max((ll)0, Z[k] - Z[i]);
    }
  }
  // dpテーブルの初期化
  dp.resize(500000, vector<ll>(21, 0)); // すべて0で初期化しておく

  int ans = rec((1 << N) - 1, 0);
  cout << ans << endl;
}