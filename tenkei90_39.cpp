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

vector<vector<ll>> tree;
vector<ll> dp;
void dfs(ll pos, ll pre) {
  dp[pos] = 1;
  for(ll i : tree[pos]) {
    if(i != pre) {
      dfs(i, pos); // 次の行き先, 直前のノード
      dp[pos] += dp[i]; // 子より下の子の個数を現在のノードに足し込む
    } 
  }
}

int main() {
  int N; cin >> N;
  tree.resize(N); dp.resize(N + 10, 0);
  REP(i, N - 1) {
    ll a, b; cin >> a >> b;
    --a; --b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  dfs(0, -1);
  ll ans = 0;
  REP(i, N) {
    ans += dp[i] * (N - dp[i]);
  }
  cout << ans << endl;
}