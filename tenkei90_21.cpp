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

vector<ll> g;
vector<vector<ll>> tree, tree_reverse;
vector<bool> f, f_reverse;
void dfs(ll v) {
  f[v] = true;
  for(int i = 0; i < tree[v].size(); ++i) {
    if(f[tree[v][i]]) continue;
    dfs(tree[v][i]);
  }
  g.push_back(v);
}

ll res = 0;
void dfs_reverse(ll v) {
  f_reverse[v] = true;
  res++;
  for(int i = 0; i < tree_reverse[v].size(); ++i) {
    if(f_reverse[tree_reverse[v][i]]) continue;
    dfs_reverse(tree_reverse[v][i]);
  }
}

int main() {
  ll N, M; cin >> N >> M;
  tree.resize(N); tree_reverse.resize(N); f.resize(N, false); f_reverse.resize(N, false);
  REP(i, M) {
    ll A, B; cin >> A >> B; A--; B--;
    tree[A].push_back(B);
    tree_reverse[B].push_back(A);
  }
  for(int i = 0; i < N; ++i) {
    if(f[i]) continue;
    dfs(i);
  }
  ll ans = 0;
  for(int i = g.size() - 1; i >= 0; --i) {
    if(f_reverse[g[i]]) continue;
    res = 0;
    dfs_reverse(g[i]);
    ans += res * (res - 1) * 0.5; // nC2
  }
  cout << ans << endl;
}