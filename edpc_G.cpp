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

vector<ll> dp;
vector<bool> flag;
vector<vector<ll>> tree;
ll f(ll i) {
  // すでにdpに答えがあるとき
  if(flag[i] == true) return dp[i];
  flag[i] = true;

  ll res = 0;
  // 遷移
  for(auto y : tree[i]) {
    chmax(res, f(y) + 1);
  }

  return dp[i] = res;
}

int main() {
  // DAG上のトポロジカルソート！

  ll N, M; cin >> N >> M;
  tree.resize(N); flag.resize(N, false);
  REP(i, M) {
    ll x, y; cin >> x >> y;
    --x; --y;
    tree[x].push_back(y);
  }
  dp.resize(N + 100, 0);
  ll ans = 0;
  REP(i, N) chmax(ans, f(i));
  cout << ans << endl;
}