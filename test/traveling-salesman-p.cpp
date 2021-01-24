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

vector<vector<int>> tree;
vector<vector<int>> dp;
const int INF = 1000100100; // 十分大きな値

int V, E;
int rec(int S, int v) {
  if(S == 0) { // どのノードも通っていなければ
    if(v == 0) return 0; // スタート地点にいたら(つまり初期値は0)
    else return INF;
  }

  if((S & (1 << v)) == 0) return INF; // SにVが含まれていなければ

  int &ret = dp[S][v];
  if(ret != 0) return ret; // すでにそのノードを見ていたら

  ret = INF;
  REP(u, V) {
    chmin(ret, rec(S ^ (1 << v), u) + tree[u][v]);
  }
  return ret;
}

int main() {
  cin >> V >> E;
  vector<int> s(E), t(E), d(E); REP(i, E) cin >> s[i] >> t[i] >> d[i];
  tree.resize(21, vector<int>(21, INF));
  REP(i, E) { // 隣接行列を作成する
    tree[s[i]][t[i]] = d[i];
  }
  dp.resize(50000, vector<int>(21, 0)); // DPテーブルには余裕をもたせる、テーブルは0で初期化しておく

  int ans = rec((1 << V) - 1, 0);
  if(ans != INF) cout << ans << endl;
  else cout << -1 << endl; // 到達不可能なノードが存在した
}
